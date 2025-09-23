from sys import stdin

sticks = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
numbers = [0] * 2001

for i in range(1, 10):
    numbers[sticks[i]] += 1

for i in range(2001):
    for s in sticks:
        if i >= s:
            numbers[i] += numbers[i - s]

numbers[6] += 1

for i in range(1, 2001):
    numbers[i] += numbers[i - 1]

for line in stdin:
    print(numbers[int(line)])
