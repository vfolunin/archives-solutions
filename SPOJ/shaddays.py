from datetime import datetime, timedelta


def solve():
    date = datetime.strptime(input(), "%d-%m-%Y").date()
    date += timedelta(days=int(input()))

    print(date.strftime("%d-%m-%Y"))


test_count = int(input())
for test in range(test_count):
    solve()