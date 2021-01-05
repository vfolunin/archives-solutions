from sys import stdin

for line in stdin:
    n = int(line)
    if n:
        print(1 if n % 17 == 0 else 0)
