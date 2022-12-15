from re import findall
from sys import stdin


class Segment:
    def __init__(self, l, r):
        self.l = l
        self.r = r

    def length(self):
        return self.r - self.l + 1

    def intersects_with(self, that):
        return self.l <= that.r + 1 and that.l <= self.r + 1

    def merge(self, that):
        self.l = min(self.l, that.l)
        self.r = max(self.r, that.r)


def test_y(coords, y):
    segments = []

    for ax, ay, bx, by in coords:
        abx, aby = abs(ax - bx), abs(ay - by)
        dist = abx + aby

        dy = abs(ay - y)
        if dy >= dist:
            continue
        dx = dist - dy

        segment = Segment(ax - dx, ax + dx)

        i = 0
        while i < len(segments):
            if segment.intersects_with(segments[i]):
                segment.merge(segments[i])
                segments.pop(i)
            else:
                i += 1

        segments.append(segment)

    return min(segment.r for segment in segments) + 1 if len(segments) > 1 else -1


coords = [[int(match) for match in findall('=(-?\d+)', line)] for line in stdin]

y = 0
while 1:
    if y % 10000 == 0:
        print(y)
    x = test_y(coords, y)
    if x != -1:
        break
    y += 1

print(x, y, x * 4000000 + y)
