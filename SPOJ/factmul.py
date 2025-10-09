n = int(input())

mod = 109546051211
factorial, res = 1, 1
for i in range(1, n + 1):
    factorial = factorial * i % mod
    res = res * factorial % mod

print(res)