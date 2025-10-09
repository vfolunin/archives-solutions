from sys import stdin

count = [0, 0, 1]
while len(count) < 1000:
    count.append(count[-2] * 2 + count[-1])

for line in stdin:
    n = int(line)

    print(count[n])