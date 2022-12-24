from collections import deque
from sys import stdin


class Blizzard:
    def __init__(self, y, x, dy, dx):
        self.y = y
        self.x = x
        self.dy = dy
        self.dx = dx

    def get_coords(self, h, w, t):
        y = (self.y - 1 + self.dy * t) % (h - 2) + 1
        x = (self.x - 1 + self.dx * t) % (w - 2) + 1
        return y, x


def bfs(a, blocked, h, w, limit):
    visited = set()
    q = deque()

    visited.add((0, 1, 0))
    q.append((0, 1, 0))

    dy = [-1, 0, 1, 0, 0]
    dx = [0, 1, 0, -1, 0]

    while q:
        y, x, t = q.popleft()

        if y == h - 1:
            return 1

        for d in range(len(dy)):
            ty = y + dy[d]
            tx = x + dx[d]

            if (0 <= ty < h and 0 <= tx < w and a[ty][tx] != '#' and t + 1 <= limit and
                    (ty, tx, t + 1) not in visited and t + 1 not in blocked[ty][tx]):
                visited.add((ty, tx, t + 1))
                q.append((ty, tx, t + 1))

    return 0


a = []
blizzards = []
for y, line in enumerate(stdin):
    a.append(line.strip())
    for x in range(len(line)):
        if line[x] == '^':
            blizzards.append(Blizzard(y, x, -1, 0))
        elif line[x] == '>':
            blizzards.append(Blizzard(y, x, 0, 1))
        elif line[x] == 'v':
            blizzards.append(Blizzard(y, x, 1, 0))
        elif line[x] == '<':
            blizzards.append(Blizzard(y, x, 0, -1))

h = len(a)
w = len(a[0])

blocked = [[set() for x in range(w)] for y in range(h)]
for t in range(1000):
    blocked_set = set()
    for blizzard in blizzards:
        blocked_set.add(blizzard.get_coords(h, w, t))

    for y, x in blocked_set:
        blocked[y][x].add(t)

    if bfs(a, blocked, h, w, t):
        print(t)
        break
