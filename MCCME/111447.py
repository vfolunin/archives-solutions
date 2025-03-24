from math import factorial

n, k = [int(_) for _ in input().split()]

print(factorial(n) // factorial(k) // (factorial(5) ** k) // factorial(n - 5 * k) if n >= 5 * k else 0)