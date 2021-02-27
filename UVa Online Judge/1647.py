from sys import stdin

a = [0, 0, 1]
while len(a) <= 1000:
    a.append(a[-1] + 2 * a[-2])

for line in stdin:
    print(a[int(line)])
