from sys import stdin

lines = [line.strip() for line in stdin]

nums = [int(_) for _ in lines[0].split(': ')[1].split()]

line_index = 2
while line_index < len(lines):
    line_index += 1

    segments = []
    while line_index < len(lines) and lines[line_index]:
        segments.append([int(_) for _ in lines[line_index].split()])
        line_index += 1

    line_index += 1

    for i in range(len(nums)):
        for bl, al, count in segments:
            if al <= nums[i] < al + count:
                nums[i] += bl - al
                break

print(min(nums))
