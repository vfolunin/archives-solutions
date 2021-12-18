from sys import stdin


def add(num, index, value, root=True):
    if type(num[index]) == int:
        num[index] += value
    else:
        add(num[index], index if not root else 1 - index, value, False)


def explode(num, depth):
     for i in range(2):
        if type(num[i]) != list:
            continue

        if depth >= 3:
            a, b = num[i]
            num[i] = 0
            if i == 0:
                add(num, 1, b)
                b = 0
            else:
                add(num, 0, a)
                a = 0
            return a, b

        a, b = explode(num[i], depth + 1)
        if a is not None and b is not None:
            if i == 0:
                add(num, 1, b)
                b = 0
            else:
                add(num, 0, a)
                a = 0
            return a, b
     return None, None


def split(num):
    for i in range(2):
        if type(num[i]) == int:
            if num[i] >= 10:
                num[i] = [num[i] // 2, num[i] - num[i] // 2]
                return True
        elif split(num[i]):
            return True
    return False


def reduce(num):
    while True:
        while explode(num, 0)[0] is not None:
            pass
        if not split(num):
            break


def magnitude(num):
    if type(num) == int:
        return num
    return 3 * magnitude(num[0]) + 2 * magnitude(num[1])


res = []
for line in stdin:
    arg = eval(line)
    res = [res, arg] if len(res) else arg
    reduce(res)

print(magnitude(res))
