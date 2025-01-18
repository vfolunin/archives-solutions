from sys import stdin

for line in stdin:
    print(sum(float(_) for _ in line.replace(' ', '').split(',')))