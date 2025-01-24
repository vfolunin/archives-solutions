def solve():
    x, p, mod = [int(_) for _ in input().split()]

    print(pow(x, p, mod))


n = int(input())

for i in range(n):
    solve()