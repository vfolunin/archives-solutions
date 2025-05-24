n = int(input())

res = 1
while n != 1:
    n = n * 3 + 1 if n % 2 else n // 2
    res += 1

print(res)
