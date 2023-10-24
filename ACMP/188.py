from math import factorial

n = int(input())

res = 0
for i in range(n + 1):
    res += factorial(n) // factorial(i) * (-1 if i % 2 else 1)

print(res)
