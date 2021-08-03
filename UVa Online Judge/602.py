def is_leap_julian(y):
    return y % 4 == 0


def is_leap_gregorian(y):
    return y % 400 == 0 or y % 4 == 0 and y % 100 != 0


def is_leap(y):
    return is_leap_julian(y) if y <= 1752 else is_leap_gregorian(y)


def days_in_month(m, y):
    if m == 2:
        return 29 if is_leap(y) else 28
    if m in [4, 6, 9, 11]:
        return 30
    return 31


def is_legal(d, m, y):
    if y == 1752 and m == 9:
        return 1 <= d <= 2 or 14 <= d <= 30
    return 1 <= m <= 12 and 1 <= d <= days_in_month(m, y)


def weekday_julian(d, m, y):
    a = (14 - m) // 12
    Y = y + 4800 - a
    M = m + 12 * a - 3
    return (d + (153 * M + 2) // 5 + 365 * Y + Y // 4 - 32083) % 7


def weekday_gregorian(d, m, y):
    from calendar import weekday
    return weekday(y, m, d)


def solve():
    from calendar import month_name, day_name
    m, d, y = [int(_) for _ in input().split()]

    if not m and not d and not y:
        return 0

    if is_legal(d, m, y):
        w = weekday_julian(d, m, y) if (y, m, d) <= (1752, 9, 2) else weekday_gregorian(d, m, y)
        print('{} {}, {} is a {}'.format(month_name[m], d, y, day_name[w]))
    else:
        print('{}/{}/{} is an invalid date.'.format(m, d, y))
    return 1


while solve():
    pass
