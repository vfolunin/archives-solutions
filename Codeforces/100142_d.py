import sys

sys.stdin = open('nosimple.in',  'r')
sys.stdout = open('nosimple.out',  'w')

x, p, mod = [int(_) for _ in input().split()]

print(pow(x, p, mod))
