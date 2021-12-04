from sys import stdin

a = [int(line) for line in stdin]

increase_count = 0
for i in range(3, len(a)):
    increase_count += a[i - 2] + a[i - 1] + a[i] > a[i - 3] + a[i - 2] + a[i - 1]

print(increase_count)
