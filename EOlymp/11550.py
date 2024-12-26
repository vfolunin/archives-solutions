target_count, target_sum = [int(_) for _ in input().split()]

ways = [[0 for sum in range(target_sum + 1)] for count in range(target_count + 1)]
ways[0][0] = 1

for count in range(1, target_count + 1):
    for sum in range(target_sum + 1):
        for last in range(1, sum + 1):
            ways[count][sum] += ways[count - 1][sum - last]

print(ways[target_count][target_sum])