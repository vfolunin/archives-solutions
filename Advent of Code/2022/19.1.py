from functools import lru_cache
from re import findall
from sys import stdin


@lru_cache(maxsize=None)
def rec(time, robots, costs, resources):
    if time == 24:
        return resources[3]

    res = resources[3] + (24 - time) * robots[3]

    for type in range(len(robots)):
        make_time = 0
        for i in range(len(robots)):
            if robots[i]:
                make_time = max(make_time, (costs[type][i] - resources[i] + robots[i] - 1) // robots[i])
            elif costs[type][i]:
                make_time = 100
                break

        if time + make_time + 1 >= 24:
            continue

        next_robots = list(robots)
        next_robots[type] += 1

        next_resources = list(resources)
        for i in range(len(costs)):
            next_resources[i] -= costs[type][i]
        for i in range(len(robots)):
            next_resources[i] = min(next_resources[i] + robots[i] * (make_time + 1), 20)

        res = max(res, rec(time + make_time + 1, tuple(next_robots), costs, tuple(next_resources)))

    return res


def solve(args):
    plan_index = args[0]
    robots = (1, 0, 0, 0)
    costs = [[0 for j in range(4)] for i in range(4)]
    costs[0][0] = args[1]
    costs[1][0] = args[2]
    costs[2][0] = args[3]
    costs[2][1] = args[4]
    costs[3][0] = args[5]
    costs[3][2] = args[6]
    resources = (0, 0, 0, 0)
    plan_value = rec(0, robots, tuple(tuple(cost) for cost in costs), resources)
    print(plan_index, plan_value)
    return plan_index * plan_value


res = 0
for line in stdin:
    res += solve([int(_) for _ in findall('\d+', line)])

print(res)
