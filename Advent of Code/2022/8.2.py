from sys import stdin


def get_score_in_row(a):
    for i in range(1, len(a)):
        if a[0] <= a[i]:
            return i
    return len(a) - 1


def get_score(a, y, x):
    return (get_score_in_row([a[i][x] for i in range(y, -1, -1)]) *
            get_score_in_row([a[i][x] for i in range(y, len(a))]) *
            get_score_in_row([a[y][i] for i in range(x, -1, -1)]) *
            get_score_in_row([a[y][i] for i in range(x, len(a[0]))]))


a = [line.strip() for line in stdin]
res = 0
for y in range(len(a)):
    for x in range(len(a[0])):
        res = max(res, get_score(a, y, x))
print(res)
