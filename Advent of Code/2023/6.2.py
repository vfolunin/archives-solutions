from sys import stdin

lines = [line.strip() for line in stdin]

time = int(''.join([c for c in lines[0] if c.isdigit()]))
distance = int(''.join([c for c in lines[1] if c.isdigit()]))

res = 0

for press_time in range(time):
    res += press_time * (time - press_time) > distance

print(res)
