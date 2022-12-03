from sys import stdin


def get_points(c):
    if c.islower():
        return ord(c) - ord('a') + 1
    else:
        return ord(c) - ord('A') + 27


score = 0
lines = [line.strip() for line in stdin]
for i in range(0, len(lines), 3):
    a = set(lines[i])
    b = set(lines[i + 1])
    c = set(lines[i + 2])
    score += get_points(list(a.intersection(b).intersection(c))[0])

print(score)
