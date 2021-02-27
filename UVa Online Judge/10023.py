def solve(test):
    input()
    n = int(input())

    l, r = -1, n + 1
    while l + 1 < r:
        m = (l + r) // 2
        if m ** 2 <= n:
            l = m
        else:
            r = m

    if test:
        print()
    print(l)


n = int(input())
for i in range(n):
    solve(i)
