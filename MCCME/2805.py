value, res = '', ''

for c in input():
    if c.isdigit():
        value += c
    else:
        if value:
            res += bin(int(value))[2:]
        value = ''
        res += c

if value:
    res += bin(int(value))[2:]

print(res)
