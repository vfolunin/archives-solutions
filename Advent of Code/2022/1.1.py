from sys import stdin

cur_sum, max_sum = 0, 0
for line in stdin:
    if line.strip() != '':
        cur_sum += int(line.strip())
    else:
        max_sum = max(max_sum, cur_sum)
        cur_sum = 0
max_sum = max(max_sum, cur_sum)

print(max_sum)
