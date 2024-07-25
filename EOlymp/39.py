start_count, index, limit = [int(_) for _ in input().split()]

a = [start_count, start_count]
for i in range(2, index):
    a.append(a[-2] + a[-1] + 1)

print(abs(limit - a[-1]))
