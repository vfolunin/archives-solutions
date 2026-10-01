from math import factorial, gcd, prod

input()
a = [int(_) for _ in input().split()]

num = prod(factorial(value) for value in a) * factorial(len(a))
den = factorial(sum(a))

g = gcd(num, den)

print(f'{num // g}/{den // g}')