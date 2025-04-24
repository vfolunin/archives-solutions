def is_prime(n):
    d = 2
    while d * d <= n:
        if n % d == 0:
            return 0
        d += 1
    return 1


size = int(input())

res = [0 for _ in range(size + 1)]
res[0] = res[1] = 1
for i in range(2, len(res)):
    if i == 2 or not is_prime(i):
        res[i] = res[i - 1] + res[i - 2]

print(res[size])
