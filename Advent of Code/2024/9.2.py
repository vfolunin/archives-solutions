s = input()

occupied, free = [], []
start = 0
id = 0
for i in range(len(s)):
    count = int(s[i])
    if i % 2:
        free.append([start, count])
    else:
        occupied.append([start, count, id])
        id += 1
    start += count

for i in range(len(occupied) - 1, -1, -1):
    for j in range(len(free)):
        if free[j][0] < occupied[i][0] and free[j][1] >= occupied[i][1]:
            occupied[i][0] = free[j][0]
            free[j] = [free[j][0] + occupied[i][1], free[j][1] - occupied[i][1]]
            break

res = 0
for start, count, id in occupied:
    for i in range(count):
        res += id * (start + i)

print(res)
