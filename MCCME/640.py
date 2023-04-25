from datetime import date, timedelta

target_day, target_month = [int(_) for _ in input().split()]
day, month, year = [int(_) for _ in input().split()]

cur_date = date(year, month, day)
res = 0

while cur_date.day != target_day or cur_date.month != target_month:
    cur_date += timedelta(days=1)
    res += 1

print(res)
