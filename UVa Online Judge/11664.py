def solve():
    size, board, x, y = [int(_) for _ in input().split()]
    if not size:
        return 0

    y -= 1
    x -= 1
    dy = [1, 0, -1, 0]
    dx = [0, 1, 0, -1]
    d = 0

    while 0 <= y < size and 0 <= x < size:
        if y == size - 1 and x == size - 1:
            print("Yes")
            return 1

        mask = 1 << ((size - 1 - y) * size + size - 1 - x)
        d = (d + 1) % 4 if board & mask else (d + 3) % 4
        board ^= mask
        y += dy[d]
        x += dx[d]

    print('Kaputt!')
    return 1


while solve():
    pass
