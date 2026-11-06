from itertools import permutations


def decode(s, digits):
    return int(''.join(digits[ord(c) - ord('a')] for c in s))


s = input()
a = s[:s.index('+')]
b = s[s.index('+') + 1:s.index('=')]
c = s[s.index('=') + 1:]

for digits in permutations('0123456789', 5):
    if decode(a, digits) + decode(b, digits) == decode(c, digits):
        print(''.join(digits))
        exit(0)

print('impossible')