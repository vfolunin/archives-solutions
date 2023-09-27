input()
count = [int(_) for _ in input().split()]

ways1, ways2, ways3 = 0, 0, 0
for i in range(len(count)):
    ways1, ways2, ways3 = ways1 + count[i], ways2 + ways1 * count[i], ways3 + ways2 * count[i]

print(ways3)
