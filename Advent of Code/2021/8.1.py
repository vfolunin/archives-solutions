from sys import stdin

digit_count = 0
for line in stdin:
    output = line.split(' | ')[1].split()
    for digit in output:
        digit_count += len(digit) in [2, 3, 4, 7]

print(digit_count)
