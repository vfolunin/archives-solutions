s = input()

count = 0
res = 0

for c in s[1:]:
    if c.isdigit():
        count = count * 10 + int(c)
    else:
        res += count if count else 1
        count = 0
res += count if count else 1

print(res)