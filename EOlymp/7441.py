n = int(input())

res = 1
for i in range(2, n + 1):
    res = res * i % 3469708049238200000
    if res == 0:
        break

print(res)
