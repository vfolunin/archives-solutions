a = [[int(_) for _ in input().split()] for y in range(2)]

res = []
while a != [[1, 0], [0, 1]]:
    if a[0][0] > a[1][0]:
        res.append(1)
        a[0][0] -= a[1][0]
        a[0][1] -= a[1][1]
    else:
        res.append(0)
        a[1][0] -= a[0][0]
        a[1][1] -= a[0][1]

print(*res, sep='')