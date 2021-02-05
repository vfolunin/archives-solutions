def solve():
    n, k = [int(_) for _ in input().split()]

    if not n and not k:
        return 0

    res = 1
    for i in range(max(k, n - k) + 1, n + 1):
        res *= i
    for i in range(1, min(k, n - k) + 1):
        res //= i

    print(res)
    return 1

while (solve()):
    pass
