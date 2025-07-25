from datetime import date, timedelta


def get_day(year, month, week):
    first = date(year, month, 1)
    return first + timedelta(days=(6 - first.weekday()) % 7, weeks=week - 1)


year = int(input())

print((get_day(year, 6, 3) - get_day(year, 5, 2)).days // 7, 'weeks')