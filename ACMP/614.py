from functools import lru_cache


@lru_cache(maxsize=None)
def rec(s, i, open_count):
    res = int(not open_count)

    for j in range(i, len(s)):
        if s[j] == '(':
            res += rec(s, j + 1, open_count + 1)
            break

    if open_count:
        for j in range(i, len(s)):
            if s[j] == ')':
                res += rec(s, j + 1, open_count - 1)
                break

    return res


s = input()

print(rec(s, 0, 0))
