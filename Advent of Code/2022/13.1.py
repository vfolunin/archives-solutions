from sys import stdin


def compare(a, b):
    for i in range(len(a)):
        if i == len(b):
            return 1
        if type(a[i]) == int and type(b[i]) == int:
            if a[i] != b[i]:
                return -1 if a[i] < b[i] else 1
        elif type(a[i]) == list and type(b[i]) == list:
            res = compare(a[i], b[i])
            if res:
                return res
        else:
            res = compare([a[i]] if type(a[i]) == int else a[i], [b[i]] if type(b[i]) == int else b[i])
            if res:
                return res
    return 0 if len(a) == len(b) else -1


lines = [line.strip() for line in stdin]

res = 0
for i in range(0, len(lines), 3):
    if compare(eval(lines[i]), eval(lines[i + 1])) == -1:
        res += i // 3 + 1

print(res)
