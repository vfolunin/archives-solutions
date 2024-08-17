target_size, target_sum = [int(_) for _ in input().split()]

ways = [[0 for sum in range(target_sum + 1)] for size in range(target_size + 1)]
for digit in range(1, min(10, target_sum + 1)):
    ways[1][digit] = 1

for size in range(1, target_size):
    for sum in range(target_sum + 1):
        for digit in range(10):
            if sum + digit <= target_sum:
                ways[size + 1][sum + digit] += ways[size][sum]

print(ways[target_size][target_sum])