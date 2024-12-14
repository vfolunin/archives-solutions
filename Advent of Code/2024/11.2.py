from functools import lru_cache

@lru_cache(maxsize=None)
def count(value, move_count):
    if move_count == 0:
        return 1

    s = str(value)
    if len(s) % 2 == 0:
        return count(int(s[:len(s) // 2]), move_count - 1) + count(int(s[len(s) // 2:]), move_count - 1)
    else:
        return count(max(value * 2024, 1), move_count - 1)


a = [int(_) for _ in input().split()]

res = 0
for value in a:
    res += count(value, 75)

print(res)