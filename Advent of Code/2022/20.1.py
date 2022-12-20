from sys import stdin

a = [[i, int(line.strip())] for i, line in enumerate(stdin)]

for i in range(len(a)):
    index = 0
    while a[index][0] != i:
        index += 1

    move_count = a[index][1] % (len(a) - 1)
    for j in range(move_count):
        a[index], a[(index + 1) % len(a)] = a[(index + 1) % len(a)], a[index]
        index = (index + 1) % len(a)
    a[index][0] = -1

zero_index = a.index([-1, 0])
res = sum(a[(zero_index + offset) % len(a)][1] for offset in range(1000, 3001, 1000))
print(res)
