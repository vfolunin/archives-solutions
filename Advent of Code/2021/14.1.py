from collections import defaultdict
from sys import stdin


def update(template, rules):
    new_template = [template[0]]
    for i in range(len(template) - 1):
        pair = template[i:i + 2]
        new_template.append(rules[pair] if pair in rules else '')
        new_template.append(template[i + 1])
    return ''.join(new_template)


lines = [line.strip() for line in stdin.readlines()]
template = lines[0]
rules = dict(tuple(line.split(' -> ')) for line in lines[2:])

for i in range(10):
    template = update(template, rules)

count = defaultdict(int)
for c in template:
    count[c] += 1

print(max(count.values()) - min(count.values()))
