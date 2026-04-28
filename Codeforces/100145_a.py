from math import lcm

n = int(input())

print(lcm(*range(1, n + 1)) - 1)