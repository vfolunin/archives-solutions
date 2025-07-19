n = int(input())

mod = 10 ** 10

print(sum(pow(i, i, mod) for i in range(1, n + 1)) % mod)