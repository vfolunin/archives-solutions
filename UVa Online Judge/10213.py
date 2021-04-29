def c(n, k):
    res = 1
    for i in range(n, n - k, -1):
        res *= i
    for i in range(1, k + 1):
        res //= i
    return res


def solve():
    n = int(input())
    print(c(n, 4) + c(n - 1, 2) + n)


n = int(input())
for i in range(n):
    solve()