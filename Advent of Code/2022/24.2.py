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


def bfs(a, blocked, h, w, start_y, start_x, start_t, target_y, limit):
    visited = set()
    q = deque()

    visited.add((start_y, start_x, start_t))
    q.append((start_y, start_x, start_t))

    dy = [-1, 0, 1, 0, 0]
    dx = [0, 1, 0, -1, 0]

    while q:
        y, x, t = q.popleft()

        if y == target_y:
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
t1, t2 = 0, 0

for t in range(1000):
    blocked_set = set()
    for blizzard in blizzards:
        blocked_set.add(blizzard.get_coords(h, w, t))

    for y, x in blocked_set:
        blocked[y][x].add(t)

    if bfs(a, blocked, h, w, 0, 1, 0, h - 1, t):
        t1 = t
        break

for t in range(t1, t1 + 1000):
    blocked_set = set()
    for blizzard in blizzards:
        blocked_set.add(blizzard.get_coords(h, w, t))

    for y, x in blocked_set:
        blocked[y][x].add(t)

    if bfs(a, blocked, h, w, h - 1, w - 2, t1, 0, t):
        t2 = t
        break

for t in range(t2, t2 + 1000):
    blocked_set = set()
    for blizzard in blizzards:
        blocked_set.add(blizzard.get_coords(h, w, t))

    for y, x in blocked_set:
        blocked[y][x].add(t)

    if bfs(a, blocked, h, w, 0, 1, t2, h - 1, t):
        print(t)
        break
