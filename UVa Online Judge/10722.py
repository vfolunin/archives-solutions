def solve():
    base, size = [int(_) for _ in input().split()]
    if not base:
        return 0

    count, count1 = base - 2, 1
    for i in range(1, size):
        count, count1 = count * (base - 1) + count1 * (base - 2), count + count1

    print(count + count1)
    return 1


while solve():
    pass
