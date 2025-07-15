n = int(input())

res = 1
for d in range(2, n):
    if d ** 9 > n:
        break
    while n % d ** 9 == 0:
        n /= d ** 9
        res *= d

print(res)