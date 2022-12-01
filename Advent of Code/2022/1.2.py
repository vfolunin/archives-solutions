from sys import stdin

sums = [0]
for line in stdin:
    if line.strip() != '':
        sums[-1] += int(line.strip())
    else:
        sums.append(0)

print(sum(sorted(sums)[-3:]))
