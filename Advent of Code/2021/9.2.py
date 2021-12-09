from sys import stdin


class DSU:
    def __init__(self, n):
        self.id = list(range(n))
        self.size = [1 for i in range(n)]

    def find(self, i):
        if self.id[i] != i:
            self.id[i] = self.find(self.id[i])
        return self.id[i]

    def merge(self, i, j):
        ri, rj = self.find(i), self.find(j)
        if ri == rj:
            return
        if self.size[ri] < self.size[rj]:
            self.id[ri] = rj
            self.size[rj] += self.size[ri]
        else:
            self.id[rj] = ri
            self.size[ri] += self.size[rj]


a = [line.strip() for line in stdin]
h, w = len(a), len(a[0])

dsu = DSU(h * w)

for y in range(h):
    for x in range(w):
        if a[y][x] == '9':
            continue
        for dy, dx in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            ty, tx = y + dy, x + dx
            if 0 <= ty < h and 0 <= tx < w and a[y][x] >= a[ty][tx]:
                dsu.merge(y * w + x, ty * w + tx)

basins = [dsu.size[i] for i in range(h * w) if dsu.id[i] == i]
basins.sort(reverse=True)

print(basins[0] * basins[1] * basins[2])
