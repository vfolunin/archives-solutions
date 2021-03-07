from sys import stdin

a = [1, 1]
for i in range(500):
    a.append(a[-1] + 2 * a[-2])

for line in stdin:
    print(a[int(line)])
