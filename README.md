# S3 DSA Lab

Semester 3 Data Structures lab programs in C, with print-ready A4 PDFs for hard-copy submission.

## Experiments

| # | Program | Source | Printable |
|---|---|---|---|
| 01 | Stack using Array | [program.c](experiments/01-stack-array/program.c) | [PDF](experiments/01-stack-array/printable.pdf) |
| 02 | Circular Queue using Array | [program.c](experiments/02-circular-queue/program.c) | [PDF](experiments/02-circular-queue/printable.pdf) |
| 03 | Infix to Postfix Conversion | [program.c](experiments/03-infix-to-postfix/program.c) | [PDF](experiments/03-infix-to-postfix/printable.pdf) |
| 04 | Linear Queue using Array | [program.c](experiments/04-linear-queue/program.c) | [PDF](experiments/04-linear-queue/printable.pdf) |
| 05 | Polynomial Addition using Arrays | [program.c](experiments/05-polynomial-addition-array/program.c) | [PDF](experiments/05-polynomial-addition-array/printable.pdf) |
| 06 | Browser Navigation using Doubly Linked List | [program.c](experiments/06-browser-navigation/program.c) | [PDF](experiments/06-browser-navigation/printable.pdf) |
| 07 | Polynomial Addition using Linked List | [program.c](experiments/07-polynomial-addition-linked-list/program.c) | [PDF](experiments/07-polynomial-addition-linked-list/printable.pdf) |
| 08 | Quick Sort | [program.c](experiments/08-quick-sort/program.c) | [PDF](experiments/08-quick-sort/printable.pdf) |
| 09 | Prefix and Postfix Traversal | [program.c](experiments/09-prefix-postfix-traversal/program.c) | [PDF](experiments/09-prefix-postfix-traversal/printable.pdf) |
| 10 | Binary Search | [program.c](experiments/10-binary-search/program.c) | [PDF](experiments/10-binary-search/printable.pdf) |
| 11 | Depth First Search (DFS) | [program.c](experiments/11-dfs/program.c) | [PDF](experiments/11-dfs/printable.pdf) |
| 12 | Spell Checker using Hashing | [program.c](experiments/12-spell-checker-hashing/program.c) | [PDF](experiments/12-spell-checker-hashing/printable.pdf) |

## Print pack

For convenience, all twelve printable sheets are also merged into [`S3_DSA_Lab_All_12.pdf`](S3_DSA_Lab_All_12.pdf).

## Notes

- Programs intentionally keep a simple textbook/lab style.
- The stack program includes the underflow-return and menu-string fixes.
- Infix-to-postfix handles alphanumeric operands and right-associative `^` correctly.
- DFS reads adjacency-matrix digits using `%1d`, so compact rows such as `01100` work as intended.
