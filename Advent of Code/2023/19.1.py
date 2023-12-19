from sys import stdin


def process(item, workflows):
    v = 'in'
    while 1:
        if v == 'A':
            return 1
        if v == 'R':
            return 0
        for check in workflows[v]:
            if ':' in check:
                condition, to = check.split(':')
                if '<' in condition:
                    key, value = condition.split('<')
                    if item[key] < int(value):
                        v = to
                        break
                else:
                    key, value = condition.split('>')
                    if item[key] > int(value):
                        v = to
                        break
            else:
                v = check


workflows = {}
res = 0

for line in stdin:
    line = line.strip()
    if line == '':
        pass
    elif not line.startswith('{'):
        name, checks = line[:-1].split('{')
        workflows[name] = checks.split(',')
    else:
        item = {}
        for kv in line[1:-1].split(','):
            key, value = kv.split('=')
            item[key] = int(value)

        if process(item, workflows):
            res += sum(item.values())

print(res)

