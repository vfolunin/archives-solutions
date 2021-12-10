from sys import stdin


def get_match(c):
    brackets = '()[]{}<>'
    return brackets[brackets.index(c) ^ 1]


score = {')': 3, ']': 57, '}': 1197, '>': 25137}
total_score = 0

for line in stdin:
    stack = []
    for c in line.strip():
        if c in '([{<':
            stack.append(c)
        elif stack[-1] == get_match(c):
            stack.pop()
        else:
            total_score += score[c]
            break

print(total_score)
