size = int(input())

a = []
seen = set()
for y in range(size):
    a.append([int(_) for _ in input().split()])
    for value in a[y]:
        seen.add(value)

value = 1
for y in range(size):
    for x in range(size):
        if not a[y][x]:
            while value in seen:
                value += 1
            seen.add(value)
            a[y][x] = value
    print(*a[y])