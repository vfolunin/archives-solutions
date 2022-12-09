from sys import stdin

ay, ax = 0, 0
by, bx = 0, 0

dy = {'UL': -1, 'U': -1, 'UR': -1, 'R': 0, 'DR': 1, 'D': 1, 'DL': 1, 'L': 0, '': 0}
dx = {'UL': -1, 'U': 0, 'UR': 1, 'R': 1, 'DR': 1, 'D': 0, 'DL': -1, 'L': -1, '': 0}

visited = {(by, bx)}

for line in stdin:
    ad, step = line.strip().split()
    step = int(step)

    for i in range(step):
        ay += dy[ad]
        ax += dx[ad]

        if abs(ay - by) >= 2 or abs(ax - bx) >= 2:
            best_dist = 10 ** 9
            best_bd = 0

            for bd in dy:
                ty = by + dy[bd]
                tx = bx + dx[bd]
                dist = abs(ay - ty) + abs(ax - tx)
                if best_dist > dist:
                    best_dist = dist
                    best_bd = bd

            by += dy[best_bd]
            bx += dx[best_bd]

        visited.add((by, bx))

print(len(visited))
