from sys import stdin

for line in stdin:
    n = int(line)
    print(n + 1 + n % 2)