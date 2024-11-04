from math import comb, factorial

size = int(input())

ways = 0
for vowel_count in range(2, size + 1):
    ways += comb(6, vowel_count) * comb(20, size - vowel_count)
ways *= factorial(size)

res = 0
while ways:
    res += ways % 10
    ways //= 10

print(res)
