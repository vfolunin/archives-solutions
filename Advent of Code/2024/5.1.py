from collections import defaultdict
from sys import stdin

after = defaultdict(set)
res = 0

for line in stdin:
    if '|' in line:
        a, b = [int(_) for _ in line.split('|')]
        after[a].add(b)
    elif ',' in line:
        a = [int(_) for _ in line.split(',')]
        ok = 1
        for i in range(len(a)):
            for j in range(i + 1, len(a)):
                if a[i] in after[a[j]]:
                    ok = 0
        if ok:
            res += a[len(a) // 2]

print(res)
