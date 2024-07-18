n, k = [int(_) for _ in input().split()]

res = 1
for i in range(n, 0, -k):
    res *= i
    if res > 10 ** 18:
        break

if res > 10 ** 18:
    print('overflow')
else:
    print(res)