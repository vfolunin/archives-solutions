from sys import stdin

for line in stdin:
    x, p, mod = [int(_) for _ in line.split()]
    print(pow(x, p, mod))
