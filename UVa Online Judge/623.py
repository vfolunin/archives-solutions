from sys import stdin

f = [1, 1]
for i in range(2, 1001):
    f.append(f[-1] * i)

for line in stdin:
    print(line[:-1] + '!')
    print(f[int(line)])
