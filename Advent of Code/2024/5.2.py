from collections import defaultdict
from functools import cmp_to_key
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
        if not ok:
            a.sort(key=cmp_to_key(lambda a, b: -1 if b in after[a] else 1 if a in after[b] else 0))
            res += a[len(a) // 2]

print(res)
