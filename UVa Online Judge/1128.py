from sys import stdin

f = [0, 1]
while len(f) <= 100:
    f.append(3 * f[-1] - f[-2])

for line in stdin:
    print(f[int(line)])
