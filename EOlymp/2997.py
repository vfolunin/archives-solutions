from datetime import datetime, timedelta

l_year, r_year = [int(_) for _ in input().split()]
if l_year > r_year:
    l_year, r_year = r_year, l_year

l = datetime(l_year, 1, 1)
r = datetime(r_year, 12, 31)

res = 0
while l <= r:
    res += l.day == 13 and l.weekday() == 4
    l += timedelta(1)

print(res)