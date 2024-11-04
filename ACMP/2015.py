from collections import defaultdict
from math import factorial

s = input().lower()

count = defaultdict(int)
for c in s:
    if c.isalpha():
        count[c] += 1

sum = 0
for c in count:
    count[c] //= 2
    sum += count[c]

res = factorial(sum)
for c in count:
    res //= factorial(count[c])
res -= 1

print(res)