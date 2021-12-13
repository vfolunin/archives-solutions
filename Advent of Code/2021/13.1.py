from sys import stdin


def fold(points, type, coord):
    for point in points:
        if type == 'x' and point[0] >= coord:
            point[0] = 2 * coord - point[0]
        if type == 'y' and point[1] >= coord:
            point[1] = 2 * coord - point[1]


lines = [line.strip() for line in stdin.readlines()]
sep = 0
while len(lines[sep]):
    sep += 1

points = [[int(_) for _ in line.split(',')] for line in lines[:sep]]

type, coord = lines[sep + 1].split()[2].split('=')
fold(points, type, int(coord))

print(len(set((x, y) for x, y in points)))
