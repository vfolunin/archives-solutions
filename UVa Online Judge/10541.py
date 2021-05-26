def c(n, k):
    res = 1
    for i in range(n, n - k, -1):
        res *= i
    for i in range(1, k + 1):
        res //= i
    return res


def solve():
    length, number_count, *numbers = [int(_) for _ in input().split()]
    print(c(length - sum(numbers) + 1, number_count))


n = int(input())
for i in range(n):
    solve()
