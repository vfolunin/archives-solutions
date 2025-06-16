def solve():
    a, b = [int(_) for _ in input().split()]

    print(a // b, a % b)


n = int(input())

for i in range(n):
    solve()