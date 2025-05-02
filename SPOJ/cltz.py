from sys import stdin


def solve(n):
    res = 1
    while n > 1:
        if n % 2:
            n = 3 * n + 1
        else:
            n //= 2
        res += 1
    print(res)


for line in stdin:
    solve(int(line))
