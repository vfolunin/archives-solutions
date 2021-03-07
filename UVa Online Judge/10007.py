f = [1]
for i in range(1, 601):
    f.append(f[-1] * i)


def solve():
    n = int(input())
    if not n:
        return 0

    print(f[2 * n] // f[n + 1])
    return 1


while solve():
    pass
