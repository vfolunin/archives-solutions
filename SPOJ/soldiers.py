def solve():
    h, w = [int(_) for _ in input().split()]

    print(max((h + 1) // 2 * w, (w + 1) // 2 * h))


n = int(input())

for i in range(n):
    solve()