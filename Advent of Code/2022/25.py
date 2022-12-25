from sys import stdin

DIGITS = '=-012'


def to_dec(s):
    res = 0
    for c in s:
        res = res * 5 + DIGITS.find(c) - 2
    return res


def from_dec(value):
    res = []
    while value:
        rem = value % 5
        if rem < 3:
            res.append(DIGITS[rem + 2])
        else:
            res.append(DIGITS[rem - 3])
            value += rem - 1
        value //= 5
    return ''.join(res[::-1])


res = 0
for line in stdin:
    res += to_dec(line.strip())

print(from_dec(res))
