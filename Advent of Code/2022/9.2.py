from sys import stdin

y = [0] * 10
x = [0] * 10

dy = {'UL': -1, 'U': -1, 'UR': -1, 'R': 0, 'DR': 1, 'D': 1, 'DL': 1, 'L': 0, '': 0}
dx = {'UL': -1, 'U': 0, 'UR': 1, 'R': 1, 'DR': 1, 'D': 0, 'DL': -1, 'L': -1, '': 0}

visited = {(y[-1], x[-1])}

for line in stdin:
    ad, step = line.strip().split()
    step = int(step)

    for i in range(step):
        y[0] += dy[ad]
        x[0] += dx[ad]

        for j in range(1, len(y)):
            if abs(y[j - 1] - y[j]) >= 2 or abs(x[j - 1] - x[j]) >= 2:
                best_dist = 10 ** 9
                best_bd = 0

                for bd in dy:
                    ty = y[j] + dy[bd]
                    tx = x[j] + dx[bd]
                    dist = abs(y[j - 1] - ty) + abs(x[j - 1] - tx)
                    if best_dist > dist:
                        best_dist = dist
                        best_bd = bd

                y[j] += dy[best_bd]
                x[j] += dx[best_bd]

        visited.add((y[-1], x[-1]))

print(len(visited))
