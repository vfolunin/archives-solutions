from math import gcd

token, period = input().split()
whole, frac = token.split('.')
period = int(period)

num = int(whole)
den = 1
for c in frac:
    num = num * 10 + int(c)
    den *= 10

num2 = num
den2 = 1
for i in range(period):
    num2 = num2 * 10 + int(frac[len(frac) - period + i])
    den2 *= 10

num = num2 - num
den *= den2 - 1

d = gcd(num, den)
num //= d
den //= d

print(f'{num}/{den}')