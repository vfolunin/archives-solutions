times = [int(_) for _ in input().split(',')]

for day in range(80):
    for i in range(len(times)):
        if times[i]:
            times[i] -= 1
        else:
            times[i] = 6
            times.append(8)

print(len(times))
