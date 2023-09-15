max_jump, size = [int(_) for _ in input().split()]

ways = [0 for i in range(size + 1)]
ways[0] = 1
for i in range(1, size + 1):
    for jump in range(min(i, max_jump) + 1):
        ways[i] += ways[i - jump]

print(ways[size])
