from copy import deepcopy
from sys import stdin


def rec(workflows, v, item):
    if v == 'A':
        res = 1
        for l, r in item.values():
            res *= max(r - l + 1, 0)
        return res

    if v == 'R':
        return 0

    p_item = deepcopy(item)
    res = 0

    for check in workflows[v]:
        if ':' not in check:
            res += rec(workflows, check, item)
            break

        condition, to = check.split(':')

        if '<' in condition:
            key, value = condition.split('<')
            value = int(value)

            if item[key][0] < value:
                to_item = deepcopy(item)
                to_item[key][1] = min(to_item[key][1], value - 1)
                res += rec(workflows, to, to_item)

            item[key][0] = value
        else:
            key, value = condition.split('>')
            value = int(value)

            if item[key][1] > value:
                to_item = deepcopy(item)
                to_item[key][0] = max(to_item[key][0], value + 1)
                res += rec(workflows, to, to_item)

            item[key][1] = value

    for key in item:
        item[key] = p_item[key]
    return res


workflows = {}

for line in stdin:
    line = line.strip()
    if line == '':
        break

    name, checks = line[:-1].split('{')
    workflows[name] = checks.split(',')

item = {}
for key in 'xmas':
    item[key] = [1, 4000]

print(rec(workflows, 'in', item))

