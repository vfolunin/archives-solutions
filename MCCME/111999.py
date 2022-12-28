from math import factorial

n, k = [int(_) for _ in input().split()]

print(factorial(n) // (factorial(n - k) * factorial(k)))
