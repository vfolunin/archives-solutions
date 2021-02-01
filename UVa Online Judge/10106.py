from sys import stdin

lines = stdin.readlines()
for i in range(0, len(lines), 2):
    print(int(lines[i]) * int(lines[i + 1]))
