from sys import stdin

f = [1]
for i in range(1, 2001):
    f.append(f[-1] * i)

for line in stdin:
    n = int(line)
    print(f[2 * n] // (f[n] * f[n + 1]))
