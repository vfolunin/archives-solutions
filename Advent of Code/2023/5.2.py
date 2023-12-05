from sys import stdin


def split_l(segments, al):
    res = []
    for l, r in segments:
        if l < al <= r:
            res.append([l, al - 1])
            res.append([al, r])
        else:
            res.append([l, r])
    return res


def split_r(segments, ar):
    res = []
    for l, r in segments:
        if l <= ar < r:
            res.append([l, ar])
            res.append([ar + 1, r])
        else:
            res.append([l, r])
    return res


lines = [line.strip() for line in stdin]

nums = [int(_) for _ in lines[0].split(': ')[1].split()]
segments = [[nums[i], nums[i] + nums[i + 1] - 1] for i in range(0, len(nums), 2)]

line_index = 2
while line_index < len(lines):
    line_index += 1

    map_segments = []
    while line_index < len(lines) and lines[line_index]:
        map_segments.append([int(_) for _ in lines[line_index].split()])
        line_index += 1
    map_segments.sort()

    line_index += 1

    for bl, al, count in map_segments:
        segments = split_l(segments, al)
        segments = split_l(segments, al + count - 1)

    next_segments = []
    for l, r in segments:
        found = 0
        for bl, al, count in map_segments:
            if al <= l <= r < al + count:
                found = 1
                next_segments.append([l + bl - al, r + bl - al])
                break
        if not found:
            next_segments.append([l, r])
    segments = next_segments

print(min(segments)[0])
