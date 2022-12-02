from sys import stdin


def get_move_points(move):
    return ord(move) - ord('X') + 1


def get_result_points(move_a, move_b):
    a = ord(move_a) - ord('A')
    b = ord(move_b) - ord('X')
    if (a + 1) % 3 == b:
        return 6
    elif a == b:
        return 3
    else:
        return 0


score = 0
for line in stdin:
    move_a, move_b = line.strip().split()
    score += get_move_points(move_b) + get_result_points(move_a, move_b)

print(score)
