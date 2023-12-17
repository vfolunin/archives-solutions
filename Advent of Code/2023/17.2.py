from heapq import heappush, heappop
from sys import stdin


def dijkstra(a):
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    dist = {}
    q = []

    for d in range(len(dy)):
        state = (0, 0, d)
        dist[state] = 0
        heappush(q,(0, state))

    while q:
        state_dist, state = heappop(q)
        if state_dist != dist[state]:
            continue

        y, x, d = state
        if y == len(a) - 1 and x == len(a[0]) - 1:
            return dist[state]

        for td in [(d - 1) % len(dy), (d + 1) % len(dy)]:
            for steps in range(4, 11):
                ty = y + dy[td] * steps
                tx = x + dx[td] * steps

                if ty < 0 or ty >= len(a) or tx < 0 or tx >= len(a[0]):
                    continue

                tstate = ty, tx, td
                weight = sum(a[y + dy[td] * i][x + dx[td] * i] for i in range(1, steps + 1))

                if tstate not in dist or dist[tstate] > dist[state] + weight:
                    dist[tstate] = dist[state] + weight
                    heappush(q, (dist[tstate], tstate))

    return 10 ** 9


a = [[int(c) for c in line.strip()] for line in stdin]

print(dijkstra(a))
