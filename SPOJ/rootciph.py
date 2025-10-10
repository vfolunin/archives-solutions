def solve():
    a, b, c = [int(_) for _ in input().split()]

    print(a * a - 2 * b)


n = int(input())

for i in range(n):
    solve()