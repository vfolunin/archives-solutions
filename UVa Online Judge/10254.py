from sys import stdin

res, p = [0], 0
while len(res) <= 10000:
    res.extend([2 ** p] * (p + 1))
    p += 1
for i in range(1, len(res)):
    res[i] += res[i - 1]

for line in stdin:
    print(res[int(line)])
