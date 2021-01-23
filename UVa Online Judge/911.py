from sys import stdin

def factorial(n):
    res = 1
    for i in range(2, n + 1):
        res *= i
    return res

f = [factorial(n) for n in range(1000)]

lines = stdin.readlines()
for i in range(0, len(lines), 3):
    res = f[int(lines[i])]
    for token in lines[i + 2].split():
        res //= f[int(token)]
    print(res)
