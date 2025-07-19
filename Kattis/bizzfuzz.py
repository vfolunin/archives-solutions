from math import lcm

l, r, a, b = [int(_) for _ in input().split()]

d = lcm(a, b)

print(r // d - (l - 1) // d)