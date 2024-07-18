from math import lcm

n = int(input())

res = 1
for i in range(1, n + 1):
    res = lcm(res, i)

print(res - 1)