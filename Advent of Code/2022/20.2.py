from sys import stdin

a = [[i, int(line.strip()) * 811589153] for i, line in enumerate(stdin)]

for round in range(10):
    print(round)
    for i in range(len(a)):
        index = 0
        while a[index][0] != round * len(a) + i:
            index += 1

        move_count = a[index][1] % (len(a) - 1)
        for j in range(move_count):
            a[index], a[(index + 1) % len(a)] = a[(index + 1) % len(a)], a[index]
            index = (index + 1) % len(a)

        a[index][0] = (round + 1) * len(a) + i

zero_index = 0
while a[zero_index][1]:
    zero_index += 1

res = sum(a[(zero_index + offset) % len(a)][1] for offset in range(1000, 3001, 1000))
print(res)
