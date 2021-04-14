from sys import stdin

f, d = [1, 1], [1, 0]
for i in range(2, 30):
    f.append(f[i - 1] * i)
    d.append((i - 1) * (d[i - 1] + d[i - 2]))

for line in stdin:
    n, m = [int(_) for _ in line.split()]
    print(sum(d[i] * f[n] // (f[i] * f[n - i]) for i in range(n - m, n + 1)))
