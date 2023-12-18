from sys import stdin


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance_to(self, that):
        return ((self.x - that.x) ** 2 + (self.y - that.y) ** 2) ** 0.5

    def cross_product(self, that):
        return self.x * that.y - self.y * that.x


class Polygon:
    def __init__(self):
        self.points = []

    def add(self, p):
        self.points.append(p)

    def perimeter(self):
        res = 0
        for i in range(len(self.points)):
            a = self.points[i]
            b = self.points[(i + 1) % len(self.points)]
            res += a.distance_to(b)
        return res

    def area(self):
        res = 0
        for i in range(len(self.points)):
            a = self.points[i]
            b = self.points[(i + 1) % len(self.points)]
            res += a.cross_product(b)
        return abs(res) // 2


dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
dc = 'URDL'

y, x = 0, 0
polygon = Polygon()

for line in stdin:
    tokens = line.split()
    d = dc.index(tokens[0])
    steps = int(tokens[1])

    y += dy[d] * steps
    x += dx[d] * steps
    polygon.add(Point(x, y))

print(polygon.area() + int(polygon.perimeter()) // 2 + 1)
