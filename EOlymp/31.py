from datetime import date, timedelta

n = int(input())

res = 0

for i in range(n):
    l, r = [int(_) for _ in input().split()]
    l = date(l, 1, 1)
    r = date(r + 1, 1, 1)

    while l != r:
        res += l.day == 13 and l.weekday() == 4
        l += timedelta(days=1)

print(res)
