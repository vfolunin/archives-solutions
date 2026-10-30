import sys

sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

a, b = [int(_) for _ in input().split()]

print(a + b)