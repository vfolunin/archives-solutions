size = int(input())

ways1, ways2, ways3 = 0, 0, 0
for i in range(size):
    count = int(input())
    ways1, ways2, ways3 = ways1 + count, ways2 + ways1 * count, ways3 + ways2 * count

print(ways3)
