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

for line in lines[sep + 1:]:
    type, coord = line.split()[2].split('=')
    fold(points, type, int(coord))

img = [[' ' for x in range(50)] for y in range(10)]
for x, y in points:
    img[y][x] = '*'

for row in img:
    print(''.join(row))
