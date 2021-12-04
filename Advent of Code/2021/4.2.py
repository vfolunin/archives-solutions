def mark(board, number):
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == number:
                board[i][j] = -1
                return


def check_win(board):
    for i in range(len(board)):
        row, col = 1, 1
        for j in range(len(board)):
            row &= board[i][j] == -1
            col &= board[j][i] == -1
        if row or col:
            return 1
    return 0


def get_score(board):
    res = 0
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] != -1:
                res += board[i][j]
    return res


def play(numbers, board):
    for i, number in enumerate(numbers):
        mark(board, number)
        if check_win(board):
            return i, get_score(board) * number


from sys import stdin

lines = [line.strip() for line in stdin]
numbers = [int(_) for _ in lines[0].split(',')]
boards = [[[int(_) for _ in lines[j].split()] for j in range(i, i + 5)] for i in range(2, len(lines), 6)]

best_i, best_score = 0, 0
for board in boards:
    i, score = play(numbers, board)
    if best_i < i:
        best_i, best_score = i, score

print(best_score)
