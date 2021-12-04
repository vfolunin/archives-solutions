from sys import stdin

count = []
for line in stdin:
    line = line.strip()
    if not len(count):
        count = [[0, 0] for i in range(len(line))]
    for i in range(len(line)):
        count[i][int(line[i])] += 1

gamma, epsilon = '', ''
for i in range(len(count)):
    if count[i][0] > count[i][1]:
        gamma += '0'
        epsilon += '1'
    else:
        gamma += '1'
        epsilon += '0'

print(int(gamma, base=2) * int(epsilon, base=2))
