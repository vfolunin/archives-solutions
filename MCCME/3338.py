from math import gcd


def lcm(a, b):
    return a // gcd(a, b) * b


n = int(input())

res = 1
for i in range(1, n + 1):
    res = lcm(res, i)

print(res)
