from sys import stdin

overlap_count = 0
for line in stdin:
    segment1, segment2 = line.strip().split(',')
    l1, r1 = [int(_) for _ in segment1.split('-')]
    l2, r2 = [int(_) for _ in segment2.split('-')]
    overlap_count += l1 <= l2 <= r2 <= r1 or l2 <= l1 <= r1 <= r2

print(overlap_count)
