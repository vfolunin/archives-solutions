input()
a = [int(_) for _ in input().split()]

if max(a) == 1:
    print(len(a) * (len(a) + 1) // 2)
    exit(0)

row, res = 0, 0
for value in a:
    if value > 1:
        row += 1
    else:
        res += row * (row + 1) // 2
        row = 0
res += row * (row + 1) // 2

print(res)
