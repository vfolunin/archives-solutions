s = input()

ways = [0 for i in range(len(s) + 1)]
ways[0] = ways[1] = 1

for i in range(2, len(s) + 1):
    ways[i] = ways[i - 1]
    if 10 <= int(s[i - 2:i]) <= 33:
        ways[i] += ways[i - 2]

print(ways[-1])
