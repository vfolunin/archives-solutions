def rec(s, i, cur, res):
    if i == len(s):
        if len(res) < len(cur):
            res[:] = cur
        return

    for size in range(1, len(s) - i + 1):
        value = int(s[i:i + size])
        if value in cur or s[i] == '0' and size > 1:
            continue

        cur.append(value)
        rec(s, i + size, cur, res)
        cur.pop()


s = input()

res = []
rec(s, 0, [], res)

print('-'.join([str(_) for _ in res]))