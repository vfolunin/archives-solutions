from sys import stdin

lines = stdin.readlines()
for i in range(0, len(lines), 2):
    p = int(lines[i])
    n = int(lines[i + 1])
    res = int(n ** (1 / p)) - 1
    while res ** p != n:
        res += 1
    print(res)
