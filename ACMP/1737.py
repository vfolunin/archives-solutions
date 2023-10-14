s = input()

res = 1
for i in range(2, len(s) + 1):
    res *= i

print(res)
