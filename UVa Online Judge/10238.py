from sys import stdin


def solve(line):
    face_count, throw_count, target_sum = [int(_) for _ in line.split()]
    prev_ways = [0 if sum else 1 for sum in range(target_sum + 1)]

    for i in range(throw_count):
        ways = [0 for sum in range(target_sum + 1)]
        for points in range(1, face_count + 1):
            for sum in range(target_sum, points - 1, -1):
                ways[sum] += prev_ways[sum - points]
        prev_ways = ways

    print('{}/{}'.format(prev_ways[target_sum], face_count ** throw_count))


for line in stdin:
    solve(line)
