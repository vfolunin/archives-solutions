d = [1, 0]
for i in range(2, 1000):
    d.append((i - 1) * (d[i - 1] + d[i - 2]))


def solve():
    n = int(input())

    if n == -1:
        return 0

    print(d[n])
    return 1


while solve():
    pass
