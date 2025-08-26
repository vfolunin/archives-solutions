def solve():
    compound_count, day_count = [int(_) for _ in input().split()]

    res = 0
    while (day_count + 1) ** res < compound_count:
        res += 1

    print(res)


n = int(input())

for i in range(n):
    solve()