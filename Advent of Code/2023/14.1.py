from sys import stdin

a = [list(line.strip()) for line in stdin]

while 1:
    updated = 0
    for y in range(len(a) - 1):
        for x in range(len(a[0])):
            if a[y][x] == '.' and a[y + 1][x] == 'O':
                a[y][x], a[y + 1][x] = a[y + 1][x], a[y][x]
                updated = 1
    if not updated:
        break

res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == 'O':
            res += len(a) - y
print(res)
