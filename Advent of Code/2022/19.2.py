from functools import lru_cache
from re import findall
from sys import stdin


TIME_LIMIT = 32
ROBOT_LIMIT = [4, 20, 20]
best_res = 0


@lru_cache(maxsize=None)
def rec(time, robots, costs, resources):
    global best_res

    if time == TIME_LIMIT:
        best_res = max(best_res, resources[3])
        return resources[3]

    imaginary_robots = list(robots)
    imaginary_resources = list(resources)
    for i in range(len(imaginary_robots) - 1):
        imaginary_resources[i] += imaginary_robots[i] * (TIME_LIMIT - time)
        imaginary_robots[i + 1] += min(imaginary_resources[0] // costs[i + 1][0], imaginary_resources[i] // costs[i + 1][i])
    imaginary_res = imaginary_resources[3] + imaginary_robots[3] * (TIME_LIMIT - time)
    if best_res >= imaginary_res:
        return 0

    res = resources[3] + (TIME_LIMIT - time) * robots[3]

    for type in range(len(robots)):
        if type < len(ROBOT_LIMIT) and robots[type] >= ROBOT_LIMIT[type]:
            continue

        make_time = 0
        for i in range(len(robots)):
            if robots[i]:
                make_time = max(make_time, (costs[type][i] - resources[i] + robots[i] - 1) // robots[i])
            elif costs[type][i]:
                make_time = 100
                break

        if time + make_time + 1 >= TIME_LIMIT:
            continue

        next_robots = list(robots)
        next_robots[type] += 1

        next_resources = list(resources)
        for i in range(len(costs)):
            next_resources[i] -= costs[type][i]
        for i in range(len(robots)):
            next_resources[i] += robots[i] * (make_time + 1)

        res = max(res, rec(time + make_time + 1, tuple(next_robots), costs, tuple(next_resources)))


    best_res = max(best_res, res)
    return res


def solve(args):
    global best_res
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
    best_res = 0
    plan_value = rec(0, robots, tuple(tuple(cost) for cost in costs), resources)
    print(plan_index, plan_value)
    return plan_value


res = 1
for i, line in enumerate(stdin):
    if i == 3:
        break
    res *= solve([int(_) for _ in findall('\d+', line)])

print(res)
