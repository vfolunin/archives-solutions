base = int(input())
s = input()

value = 0
for c in s:
    value = (value * base + int(c)) % (base - 1)

res = []
while value >= base:
    res.append(value % base)
    value %= base
res.append(value)

print(*res[::-1], sep='')
