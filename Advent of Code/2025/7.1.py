from sys import stdin

xs = set()
res = 0
for line in stdin:
    for x in range(len(line)):
        if line[x] == 'S':
            xs.add(x)
        elif line[x] == '^' and x in xs:
            xs.remove(x)
            xs.add(x - 1)
            xs.add(x + 1)
            res += 1

print(res)
