f = [0, 1]
for i in range(1510):
    f.append(f[-1] + f[-2])


def solve(test):
    n = int(input())

    if not n:
        return 0

    print('Set ' + str(test) + ':')
    print((f[n + 3] - 3) // 2)
    return 1


test = 1
while solve(test):
    test += 1
