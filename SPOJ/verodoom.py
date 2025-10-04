def solve():
    n = int(input())

    print(n * (n + 1) * (n + 2) // 2)


n = int(input())

for i in range(n):
    solve()