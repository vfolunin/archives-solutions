from math import gcd

n = int(input())
for i in range(n):
    a, b = [int(_) for _ in input().split()]
    print(gcd(a, b))
