from pathlib import Path
import subprocess
import tempfile
from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import A4, landscape
from reportlab.pdfbase.pdfmetrics import stringWidth
from pypdf import PdfReader, PdfWriter

ROOT = Path(__file__).resolve().parents[1]
W, H = landscape(A4)

# One representative run per experiment. Menu-driven programs deliberately
# exercise several operations so the PDF shows the actual menus/prompts too.
EXPERIMENTS = [
    ("01-stack-array", "STACK USING ARRAY - C PROGRAM", "Stack | Array", "1\n10\n1\n20\n3\n2\n3\n4\n"),
    ("02-circular-queue", "CIRCULAR QUEUE USING ARRAY - C PROGRAM", "Circular Queue", "1\n10\n1\n20\n3\n2\n1\n30\n3\n4\n"),
    ("03-infix-to-postfix", "INFIX TO POSTFIX CONVERSION - C PROGRAM", "Stack Application", "(A+B)*C^D^E\n"),
    ("04-linear-queue", "LINEAR QUEUE USING ARRAY - C PROGRAM", "Linear Queue", "1\n10\n1\n20\n3\n2\n3\n4\n"),
    ("05-polynomial-addition-array", "POLYNOMIAL ADDITION USING ARRAYS - C PROGRAM", "Polynomial Representation", "3\n5 3\n2 1\n1 0\n3\n3 3\n4 2\n7 0\n"),
    ("06-browser-navigation", "BROWSER NAVIGATION - C PROGRAM", "Doubly Linked List", "1\ngoogle.com\n1\ngithub.com\n2\n3\n4\n5\n"),
    ("07-polynomial-addition-linked-list", "POLYNOMIAL ADDITION USING LINKED LIST - C PROGRAM", "Singly Linked List", "3\n5 3\n2 1\n1 0\n3\n3 3\n4 2\n7 0\n"),
    ("08-quick-sort", "QUICK SORT - C PROGRAM", "Divide and Conquer", "5\n40 10 30 20 50\n"),
    ("09-prefix-postfix-traversal", "PREFIX AND POSTFIX TRAVERSAL - C PROGRAM", "Binary Expression Tree", "a+b\n"),
    ("10-binary-search", "BINARY SEARCH - C PROGRAM", "Sorted Array", "7\n2 5 8 12 16 23 38\n16\n"),
    ("11-dfs", "DEPTH FIRST SEARCH (DFS) - C PROGRAM", "Adjacency Matrix", "5\n01100\n10010\n10011\n01101\n00110\n0\n"),
    ("12-spell-checker-hashing", "SPELL CHECKER USING HASHING - C PROGRAM", "Simple Hash Table", "appl\n"),
]


def fit(lines, width, height, max_size, min_size, pad=8, line_factor=1.08):
    size = max_size
    while size >= min_size:
        leading = size * line_factor
        widest = max((stringWidth(line, "Courier", size) for line in lines), default=0)
        if widest <= width - 2 * pad and len(lines) * leading <= height - 2 * pad:
            return size, leading
        size -= 0.05
    return min_size, min_size * line_factor


def wrap(lines, chars):
    out = []
    for line in lines:
        if not line:
            out.append("")
            continue
        while len(line) > chars:
            cut = line.rfind(" ", 0, chars + 1)
            if cut < 1:
                cut = chars
            out.append(line[:cut])
            line = line[cut:].lstrip()
        out.append(line)
    return out


def compile_and_run(source, stdin_text):
    with tempfile.TemporaryDirectory() as tmp:
        exe = Path(tmp) / "program"
        subprocess.run(
            ["gcc", "-std=c11", "-Wall", "-Wextra", str(source), "-o", str(exe)],
            check=True,
        )
        result = subprocess.run(
            [str(exe)], input=stdin_text, text=True,
            capture_output=True, timeout=5, check=True,
        )
        return result.stdout.rstrip().splitlines()


def draw_code(pdf, lines, x, y, width, height):
    pdf.roundRect(x, y, width, height, 6, stroke=1, fill=0)
    size, leading = fit(lines, width, height, 9.3, 7.2, 10, 1.07)
    if size >= 8.0 and len(lines) <= 58:
        pdf.setFont("Courier", size)
        cy = y + height - 10 - size
        for line in lines:
            pdf.drawString(x + 10, cy, line)
            cy -= leading
        return

    gap, pad = 10, 9
    col_w = (width - 2 * pad - gap) / 2
    best = None
    for split in range(max(10, len(lines)//2 - 15), min(len(lines)-8, len(lines)//2 + 16)):
        a, b = lines[:split], lines[split:]
        s1, _ = fit(a, col_w, height, 8.8, 7.0, 2, 1.07)
        s2, _ = fit(b, col_w, height, 8.8, 7.0, 2, 1.07)
        score = min(s1, s2) - abs(len(a)-len(b))*0.008
        if best is None or score > best[0]:
            best = (score, split, min(s1, s2))
    _, split, size = best
    leading = size * 1.07
    x1, x2 = x + pad, x + pad + col_w + gap
    pdf.setLineWidth(0.25)
    pdf.line(x1 + col_w + gap/2, y + 9, x1 + col_w + gap/2, y + height - 9)
    pdf.setFont("Courier", size)
    cy = y + height - 10 - size
    for line in lines[:split]:
        pdf.drawString(x1, cy, line)
        cy -= leading
    cy = y + height - 10 - size
    for line in lines[split:]:
        pdf.drawString(x2, cy, line)
        cy -= leading


def build_pdf(folder_name, title, subtitle, sample_input):
    folder = ROOT / "experiments" / folder_name
    source = folder / "program.c"
    code_lines = source.read_text(encoding="utf-8").rstrip().splitlines()
    output_lines = compile_and_run(source, sample_input)
    dest = folder / "printable.pdf"

    pdf = canvas.Canvas(str(dest), pagesize=(W, H))
    pdf.setTitle(title)
    margin, gap = 20, 14
    header_h = 38
    top = H - header_h - 8
    bottom = 20
    panel_h = top - bottom - 14
    usable = W - 2 * margin - gap
    left_ratio = 0.68 if len(code_lines) >= 70 else 0.63
    left_w = usable * left_ratio
    right_w = usable - left_w
    left_x = margin
    right_x = margin + left_w + gap

    pdf.setFont("Helvetica-Bold", 15)
    pdf.drawString(margin, H - 24, title)
    pdf.setFont("Helvetica", 8.5)
    pdf.drawRightString(W - margin, H - 23, subtitle)
    pdf.setLineWidth(0.7)
    pdf.line(margin, H - header_h, W - margin, H - header_h)
    pdf.setFont("Helvetica-Bold", 10)
    pdf.drawString(left_x, top, "1. PROGRAM CODE")
    pdf.drawString(right_x, top, "2. ACTUAL PROGRAM OUTPUT")
    pdf.setLineWidth(0.4)
    pdf.line(left_x + left_w + gap/2, bottom, left_x + left_w + gap/2, top + 3)

    draw_code(pdf, code_lines, left_x, bottom, left_w, panel_h)

    pdf.roundRect(right_x, bottom, right_w, panel_h, 6, stroke=1, fill=0)
    pdf.setFont("Helvetica-Bold", 8.3)
    pdf.drawString(right_x + 8, bottom + panel_h - 15, "Representative full run (captured stdout)")
    char_width = max(22, int((right_w - 16) / stringWidth("M", "Courier", 6.5)))
    shown = wrap(output_lines, char_width)
    out_size, out_lead = fit(shown, right_w, panel_h - 28, 7.5, 5.2, 8, 1.10)
    pdf.setFont("Courier", out_size)
    cy = bottom + panel_h - 32
    for line in shown:
        pdf.drawString(right_x + 8, cy, line)
        cy -= out_lead

    pdf.setFont("Helvetica-Oblique", 6.8)
    pdf.drawRightString(W - margin, 9, "S3 DSA Lab - print-ready A4 landscape")
    pdf.showPage()
    pdf.save()
    return dest


def main():
    generated = [build_pdf(*exp) for exp in EXPERIMENTS]
    writer = PdfWriter()
    for pdf_path in generated:
        for page in PdfReader(str(pdf_path)).pages:
            writer.add_page(page)
    with (ROOT / "S3_DSA_Lab_All_12.pdf").open("wb") as f:
        writer.write(f)
    print("Generated 12 printables and S3_DSA_Lab_All_12.pdf")


if __name__ == "__main__":
    main()
