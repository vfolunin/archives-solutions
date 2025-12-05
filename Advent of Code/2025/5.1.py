from sys import stdin

segments = []
res = 0
for line in stdin:
    line = line.strip()
    if '-' in line:
        segments.append([int(_) for _ in line.split('-')])
    elif line != '':
        value = int(line)
        for l, r in segments:
            if l <= value <= r:
                res += 1
                break

print(res)
