from functools import lru_cache
from sys import stdin

@lru_cache(maxsize=None)
def rec(size, depth):
    if size % 2 or depth < 0:
        return 0
    if size == 0:
        return 1
    res = 0
    for left_size in range(2, size + 1, 2):
        res += rec(left_size - 2, depth - 1) * rec(size - left_size, depth)
    return res


for line in stdin:
    size, depth = [int(_) for _ in line.split()]
    print(rec(size, depth) - rec(size, depth - 1))
