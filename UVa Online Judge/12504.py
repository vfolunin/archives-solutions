def read():
    pairs = input()[1:-1]
    if ':' in pairs:
        return sorted(pair.split(':') for pair in pairs.split(','))
    else:
        return []


def solve():
    a = read()
    b = read()

    added, removed, changed = [], [], []

    ai, bi = 0, 0
    while ai < len(a) or bi < len(b):
        if ai < len(a) and (bi == len(b) or a[ai][0] < b[bi][0]):
            removed.append(a[ai][0])
            ai += 1
        elif bi < len(b) and (ai == len(a) or a[ai][0] > b[bi][0]):
            added.append(b[bi][0])
            bi += 1
        else:
            if a[ai][1] != b[bi][1]:
                changed.append(a[ai][0])
            ai += 1
            bi += 1

    if len(added) == 0 and len(removed) == 0 and len(changed) == 0:
        print('No changes')
    else:
        if len(added):
            print('+' + ','.join(added))
        if len(removed):
            print('-' + ','.join(removed))
        if len(changed):
            print('*' + ','.join(changed))
    print()


n = int(input())
for i in range(n):
    solve()
