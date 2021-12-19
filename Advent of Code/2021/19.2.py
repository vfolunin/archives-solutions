from sys import stdin

class Scanner:
    def __init__(self, data):
        lines = data.split('\n')
        self.id = lines[0].split()[2]
        self.p = []
        self.s = [[0, 0, 0]]
        for line in lines[1:]:
            self.p.append([int(_) for _ in line.split(',')])

    def rotate_xy(self):
        for i in range(len(self.p)):
            self.p[i][0], self.p[i][1] = -self.p[i][1], self.p[i][0]
        for i in range(len(self.s)):
            self.s[i][0], self.s[i][1] = -self.s[i][1], self.s[i][0]

    def rotate_xz(self):
        for i in range(len(self.p)):
            self.p[i][0], self.p[i][2] = -self.p[i][2], self.p[i][0]
        for i in range(len(self.s)):
            self.s[i][0], self.s[i][2] = -self.s[i][2], self.s[i][0]

    def rotate_yz(self):
        for i in range(len(self.p)):
            self.p[i][1], self.p[i][2] = -self.p[i][2], self.p[i][1]
        for i in range(len(self.s)):
            self.s[i][1], self.s[i][2] = -self.s[i][2], self.s[i][1]

    def anchor_intersection(self, that, a, b):
        dx = self.p[a][0] - that.p[b][0]
        dy = self.p[a][1] - that.p[b][1]
        dz = self.p[a][2] - that.p[b][2]
        s = set(tuple(p) for p in self.p)
        res = 0
        for i in range(len(that.p)):
            if res + len(that.p) - i < 12:
                return 0
            x, y, z = that.p[i]
            res += (x + dx, y + dy, z + dz) in s
        return res

    def intersection(self, that):
        res, ra, rb = 0, 0, 0
        for a in range(len(self.p)):
            for b in range(len(that.p)):
                cur = self.anchor_intersection(that, a, b)
                if res < cur:
                    res, ra, rb = cur, a, b
        return res, ra, rb

    def max_intersection(self, that):
        res, rx, ry, rz, ra, rb = 0, 0, 0, 0, 0, 0
        for x in range(4):
            for y in range(4):
                for z in range(4):
                    cur, a, b = self.intersection(that)
                    if res < cur:
                        res, rx, ry, rz, ra, rb = cur, x, y, z, a, b
                    that.rotate_xy()
                that.rotate_xz()
            that.rotate_yz()
        return res, rx, ry, rz, ra, rb

    def merge(self, that):
        res, rx, ry, rz, ra, rb = self.max_intersection(that)
        if res < 12:
            return False

        for x in range(rx):
            that.rotate_yz()
        for y in range(ry):
            that.rotate_xz()
        for z in range(rz):
            that.rotate_xy()

        dx = self.p[ra][0] - that.p[rb][0]
        dy = self.p[ra][1] - that.p[rb][1]
        dz = self.p[ra][2] - that.p[rb][2]
        self.s.extend([[x + dx, y + dy, z + dz] for x, y, z in that.s])
        s = set(tuple(p) for p in self.p)
        for x, y, z in that.p:
            t = [x + dx, y + dy, z + dz]
            if tuple(t) not in s:
                self.p.append(t)

        return True


scanner_data = ''.join(stdin.readlines()).split('\n\n')
scanners = [Scanner(data) for data in scanner_data]

while len(scanners) > 1:
    for i in range(len(scanners)):
        for j in range(i + 1, len(scanners)):
            if scanners[i].merge(scanners[j]):
                print('Merging {} and {} (remaining: {})'.format(scanners[i].id, scanners[j].id, len(scanners)))
                scanners.pop(j)
                break
            else:
                print('Can\'t merge {} and {} (remaining: {})'.format(scanners[i].id, scanners[j].id, len(scanners)))

max_dist = 0
for x1, y1, z1 in scanners[0].s:
    for x2, y2, z2 in scanners[0].s:
        max_dist = max(max_dist, abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2))

print(max_dist)
