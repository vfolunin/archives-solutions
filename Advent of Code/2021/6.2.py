times = [int(_) for _ in input().split(',')]

count = [0 for i in range(9)]
for time in times:
    count[time] += 1

for day in range(256):
    count = count[1:] + count[:1]
    count[6] += count[8]

print(sum(count))
