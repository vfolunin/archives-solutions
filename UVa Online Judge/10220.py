from sys import stdin

def factorial(n):
    res = 1
    for i in range(1, n + 1):
        res *= i
    return res

def digit_sum(n):
    res = 0
    while n:
        res += n % 10
        n //= 10
    return res

for line in stdin:
    print(digit_sum(factorial(int(line))))
