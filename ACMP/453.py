n = int(input())

res = 2
for i in range(1, n):
    res += 10 ** i
    if res % (2 ** (i + 1)):
        res += 10 ** i

print(res)
