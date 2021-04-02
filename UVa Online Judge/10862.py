f = [0, 1]
for i in range(2000):
    f.append(3 * f[-1] - f[-2])


def solve():
    n = int(input())
    if not n:
        return 0
    print(f[n])
    return 1


while solve():
    pass
