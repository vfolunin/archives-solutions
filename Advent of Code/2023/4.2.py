from collections import defaultdict
from sys import stdin

count = defaultdict(int)

for line in stdin:
    card_id, parts = line.strip().split(':')

    card_id = int(card_id.split()[1])
    a, b = [set(part.split()) for part in parts.split('|')]
    common_count = len(a & b)

    count[card_id] += 1
    for i in range(1, common_count + 1):
        count[card_id + i] += count[card_id]

print(sum(count.values()))
