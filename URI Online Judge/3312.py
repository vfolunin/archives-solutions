from math import factorial


def is_prime(n):
    if n < 2:
        return 0
    d = 2
    while d * d <= n:
        if n % d == 0:
            return 0
        d += 1
    return 1


input()
for x in input().split():
    x = int(x)
    if is_prime(x):
        print(f'{x}! = {factorial(x)}')
