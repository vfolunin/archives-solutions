def filter(lines, val0, val1):
    for i in range(len(lines[0])):
        count = [0, 0]
        for line in lines:
            count[int(line[i])] += 1

        if count[0] > count[1]:
            lines = [line for line in lines if line[i] == val0]
        else:
            lines = [line for line in lines if line[i] == val1]

        if len(lines) == 1:
            return lines[0]


from sys import stdin

lines = [line.strip() for line in stdin]

oxygen = filter(lines[:], '0', '1')
co2 = filter(lines[:], '1', '0')

print(int(oxygen, base=2) * int(co2, base=2))
