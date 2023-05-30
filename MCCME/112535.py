n = int(input())

res = 1
while n > res:
    n //= res
    res += 1

print(res)
