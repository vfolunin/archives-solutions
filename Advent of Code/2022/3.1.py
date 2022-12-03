from sys import stdin


def get_points(c):
    if c.islower():
        return ord(c) - ord('a') + 1
    else:
        return ord(c) - ord('A') + 27


score = 0
for line in stdin:
    s = line.strip()
    a = set(s[:len(s) // 2])
    b = set(s[len(s) // 2:])
    score += get_points(list(a.intersection(b))[0])

print(score)
