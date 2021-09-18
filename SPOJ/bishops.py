from sys import stdin

for line in stdin:
    n = int(line)
    print(1 if n == 1 else 2 * n - 2)
