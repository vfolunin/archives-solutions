n = int(input())

factorial, res = 1, 0
for i in range(1, n + 1):
    factorial *= i
    res += factorial

print(res)
