def solve():
    n, p = [int(_) for _ in input().split()]

    print(n ** p - (n - 2) ** p)


n = int(input())

for i in range(n):
    solve()