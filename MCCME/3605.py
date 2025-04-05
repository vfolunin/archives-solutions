from re import sub
from sys import stdin

for line in stdin:
    print(sub(r'\\texttt{([a-zA-Z]+|\d+)}', r'\\begin{bfseries}\1\\end{bfseries}', line[:-1]))
