from collections import defaultdict
from sys import stdin


def update(pair_count, rules):
    new_pair_count = defaultdict(int)
    for pair, count in pair_count.items():
        for new_pair in rules[pair]:
            new_pair_count[new_pair] += count
    return new_pair_count


lines = [line.strip() for line in stdin.readlines()]

pair_count = defaultdict(int)
for i in range(len(lines[0]) - 1):
    pair_count[lines[0][i:i + 2]] += 1

rules = defaultdict(list)
for line in lines[2:]:
    a, b = line.split(' -> ')
    rules[a].append(a[0] + b)
    rules[a].append(b + a[1])

print(rules)
for i in range(40):
    pair_count = update(pair_count, rules)

char_count = defaultdict(int)
char_count[lines[0][0]] += 1
char_count[lines[0][-1]] += 1
for pair, count in pair_count.items():
    char_count[pair[0]] += count
    char_count[pair[1]] += count

print((max(char_count.values()) - min(char_count.values())) // 2)
