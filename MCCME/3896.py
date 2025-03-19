from math import lcm

size = int(input())
a = [int(input()) for _ in range(size)]

print(lcm(*a))
