input()
n = sum(int(_) for _ in input().split())

bit = 120
while (n & (1 << bit)) == 0:
    bit -= 1

print(1 << bit)