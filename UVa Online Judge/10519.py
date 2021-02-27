from sys import stdin

for line in stdin:
    n = int(line)
    if n == 0:
        print(1)
    else:
        print(n * (n - 1) + 2)
