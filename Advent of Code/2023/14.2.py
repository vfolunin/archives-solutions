from sys import stdin

a = [list(line.strip()) for line in stdin]

seen = {}
seen['\n'.join(''.join(row) for row in a)] = 0
i, iteration_count, found = 0, 10 ** 9, 0

while i < iteration_count:
    while 1:
        updated = 0
        for y in range(len(a) - 1):
            for x in range(len(a[0])):
                if a[y][x] == '.' and a[y + 1][x] == 'O':
                    a[y][x], a[y + 1][x] = a[y + 1][x], a[y][x]
                    updated = 1
        if not updated:
            break

    while 1:
        updated = 0
        for y in range(len(a)):
            for x in range(len(a[0]) - 1):
                if a[y][x] == '.' and a[y][x + 1] == 'O':
                    a[y][x], a[y][x + 1] = a[y][x + 1], a[y][x]
                    updated = 1
        if not updated:
            break

    while 1:
        updated = 0
        for y in range(len(a) - 1, 0, -1):
            for x in range(len(a[0])):
                if a[y][x] == '.' and a[y - 1][x] == 'O':
                    a[y][x], a[y - 1][x] = a[y - 1][x], a[y][x]
                    updated = 1
        if not updated:
            break

    while 1:
        updated = 0
        for y in range(len(a)):
            for x in range(len(a[0]) - 1, 0, -1):
                if a[y][x] == '.' and a[y][x - 1] == 'O':
                    a[y][x], a[y][x - 1] = a[y][x - 1], a[y][x]
                    updated = 1
        if not updated:
            break

    key = '\n'.join(''.join(row) for row in a)
    i += 1

    if not found and key in seen:
        found = 1
        cycle_size = i - seen[key]
        remaining = (iteration_count - i) % cycle_size
        iteration_count = i + remaining
    else:
        seen[key] = i


res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x] == 'O':
            res += len(a) - y
print(res)
