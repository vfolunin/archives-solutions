size = int(input())

ways = [[0, 0, 0] for i in range(size + 1)]
ways[0] = [1, 1, 1]
ways[1] = [2, 4, 4]

for i in range(2, size + 1):
    ways[i][0] = ways[i - 1][1] + ways[i - 1][2] + ways[i - 2][0] + ways[i - 2][1] + ways[i - 2][2]
    ways[i][1] = ways[i][0] + ways[i - 1][0] + ways[i - 1][2]
    ways[i][2] = ways[i][0] + ways[i - 1][0] + ways[i - 1][1]

print(ways[size][0])
