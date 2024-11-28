from collections import defaultdict

n = int(input())

count = defaultdict(int)

d = 2
while d * d <= n:
    while n % d == 0:
        count[d] += 1
        n //= d
    d += 1
if n > 1:
    count[n] += 1

for i, (d, count) in enumerate(count.items()):
    if i:
        print('*', end='')
    print(d, end='')
    if count > 1:
        print('^', count, sep='', end='')