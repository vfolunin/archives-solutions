def solve():
    mod, limit = [int(_) for _ in input().split()]
    a, b, c = [int(_) for _ in input().split()]

    print('YES' if (b + c + b - a) % (mod + 1) <= mod - limit else 'NO')


n = int(input())

for i in range(n):
    solve()