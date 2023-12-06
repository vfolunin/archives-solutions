from sys import stdin

lines = [line.strip() for line in stdin]

times = [int(_) for _ in lines[0].split()[1:]]
distances = [int(_) for _ in lines[1].split()[1:]]

res = 1

for time, distance in zip(times, distances):
    count = 0
    for press_time in range(time):
        count += press_time * (time - press_time) > distance

    res *= count

print(res)
