from sys import stdin

for line in stdin:
    n, a = [int(_) for _ in line.split()]
    print(sum(i * a ** i for i in range(1, n + 1)))
