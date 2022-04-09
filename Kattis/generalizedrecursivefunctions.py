def solve():
    *ab, c, d = [int(_) for _ in input().split()]
    xy = [int(_) for _ in input().split()]

    memo = {}

    def f(x, y):
        if (x, y) not in memo:
            if x > 0 and y > 0:
                memo[(x, y)] = sum(f(x - ab[i], y - ab[i + 1]) for i in range(0, len(ab), 2)) + c
            else:
                memo[(x, y)] = d
        return memo[(x, y)]

    for i in range(0, len(xy), 2):
        print(f(xy[i], xy[i + 1]))
    print()


n = int(input())
for i in range(n):
    solve()
