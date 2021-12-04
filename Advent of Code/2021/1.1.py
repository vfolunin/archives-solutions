from sys import stdin

a = [int(line) for line in stdin]

increase_count = 0
for i in range(1, len(a)):
    increase_count += a[i] > a[i - 1]

print(increase_count)
