start, finish, a, b, c = [int(_) for _ in input().split()]

ways = [0 for i in range(finish + 1)]
ways[start] = int(start < finish)

for i in range(start, finish):
    for j in [i + a, i * (b + 1), i + c]:
        if j < len(ways):
            ways[j] += ways[i]

print(ways[finish])