from sys import stdin

res = 0
for line in stdin:
    cur = 0
    for l in range(len(line)):
        for r in range(l + 1, len(line)):
            cur = max(cur, int(line[l] + line[r]))
    res += cur

print(res)
