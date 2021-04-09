from sys import stdin

l = [2, 1]
for i in range(10001):
    l.append(l[-1] + l[-2])

for line in stdin:
    print(l[int(line)])
