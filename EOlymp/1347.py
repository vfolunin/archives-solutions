n = int(input())

res = 1
d = 2
while d * d <= n:
    if n % d == 0:
        count = 0
        while n % d == 0:
            count += 1
            n //= d
        res *= count + 1
    d += 1
if n > 1:
    res *= 2

print(res)
