def solve():
    n = int(input())

    print(n * (n - 1) * (n - 2) * (n - 3) // 24 % 1000000007)


n = int(input())

for i in range(n):
    solve()