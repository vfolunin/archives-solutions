def gcd(a, b):
    return gcd(b, a % b) if b else a

n = int(input())
for i in range(n):
    a, b = [int(_) for _ in input().split(' / ')]
    d = gcd(a, b)
    print(a // d, '/', b // d)
