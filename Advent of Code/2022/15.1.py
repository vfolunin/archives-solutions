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


segments = []
points = set()

for line in stdin:
    ax, ay, bx, by = [int(match) for match in findall('=(-?\d+)', line)]
    abx, aby = abs(ax - bx), abs(ay - by)
    dist = abx + aby

    y = 2000000
    if by == y:
        points.add(bx)
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


print(sum(segment.length() for segment in segments) - len(points))
