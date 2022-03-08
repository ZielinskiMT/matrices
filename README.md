# matrices
Simple program for matrix operations, claclulation is done on command line arguments.
usage:
```
matrices matrix_A matrix_B operator
```
matrix definition format:

" row_values ; row_values; ... last_row_values"

operator: 
- \+ addition, 
- \- subtraction, 
- x multiplication

Output example:
```
$ ./build/matrices "1 1 1; 1 1 1; 1 1 1" "2 2 2; 2 2 2; 2 2 2" +
A = 
|       1       1       1       |
|       1       1       1       |
|       1       1       1       |

B = 
|       2       2       2       |
|       2       2       2       |
|       2       2       2       |

A+B = 
|       3       3       3       |
|       3       3       3       |
|       3       3       3       |
```
