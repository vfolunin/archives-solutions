from collections import deque
from sys import stdin

res = 0
for line in stdin:
    line = line.strip()

    pos = [deque() for digit in range(10)]
    for i in range(len(line)):
        pos[int(line[i])].append(i)

    start = 0
    digits = [0] * 12
    for i in range(len(digits)):
        for digit in range(9, -1, -1):
            while len(pos[digit]) and pos[digit][0] < start:
                pos[digit].popleft()
            if len(pos[digit]) and pos[digit][0] + (len(digits) - i) <= len(line):
                digits[i] = digit
                start = pos[digit][0] + 1
                break

    res += int(''.join(str(digit) for digit in digits))

print(res)
