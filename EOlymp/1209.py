from math import factorial

n = int(input())

print(f'{factorial(n - 2) / ((factorial(n // 2 - 1) ** 2) * (2 ** (n - 2))):.4f}')