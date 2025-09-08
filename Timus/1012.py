size = int(input())
base = int(input())

ways = [1, base - 1]
for i in range(2, size + 1):
    ways.append((base - 1) * (ways[i - 1] + ways[i - 2]))
ways[1] += 1

print(ways[size])