from sys import stdin

f = [0, 1]
for i in range(5000):
    f.append(f[-2] + f[-1])

for line in stdin:
    n = int(line)
    print('The Fibonacci number for {} is {}'.format(n, f[n]))
