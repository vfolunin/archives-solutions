def solve():
    disk_count, move_count = [int(_) for _ in input().split()]
    if not disk_count:
        return 0

    disk_on_peg_count = [0, 0, 0]
    for i in range(disk_count):
        disk_moves = (move_count + 2 ** i) // (2 ** (i + 1))
        peg = disk_moves % 3 if i % 2 == 0 else -disk_moves % 3
        disk_on_peg_count[peg] += 1

    print(*disk_on_peg_count)
    return 1


while solve():
    pass
