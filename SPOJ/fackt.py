from math import factorial

value = int(input())

res = 1
while factorial(res) < value:
    res += 1

print(res, len(str(factorial(2 * res))))
