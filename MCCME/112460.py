n = int(input())

f = 1
for i in range(2 - n % 2, n + 1, 2):
    f *= i

print(f)
