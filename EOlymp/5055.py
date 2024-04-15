from datetime import date

s = input()
print((date(int(s[4:]), int(s[2:4]), int(s[:2])) - date(1, 1, 1)).days + 1)
