start, finish, a, b = [int(_) for _ in input().split()]
include_size = int(input())
include = sorted([int(_) for _ in input().split()]) if include_size else []
exclude_size = int(input())
exclude = sorted([int(_) for _ in input().split()]) if exclude_size else []

if start == finish:
    print(0)
    exit(0)

include.insert(0, start)
include.append(finish)

ways = [0 for value in range(finish + 1)]
ways[start] = 1

for i in range(len(include) - 1):
    for value in range(include[i], include[i + 1]):
        if value not in exclude:
            for next_value in [value + a, value * (b + 1)]:
                if next_value < len(ways):
                    ways[next_value] += ways[value]

    for value in range(len(ways)):
        if value != include[i + 1]:
            ways[value] = 0

print(ways[finish])