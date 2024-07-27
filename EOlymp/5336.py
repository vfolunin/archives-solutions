x = int(input())
p = int(input())
mod = 10 ** 9 + 7

print(pow(x, p % mod, mod))