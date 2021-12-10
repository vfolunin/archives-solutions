from sys import stdin


def get_match(c):
    brackets = '()[]{}<>'
    return brackets[brackets.index(c) ^ 1]


score = {')': 1, ']': 2, '}': 3, '>': 4}
total_scores = []

for line in stdin:
    stack = []
    corrupt = False
    for c in line.strip():
        if c in '([{<':
            stack.append(c)
        elif stack[-1] == get_match(c):
            stack.pop()
        else:
            corrupt = True
            break

    if not corrupt:
        total_score = 0
        while len(stack):
            total_score = total_score * 5 + score[get_match(stack[-1])]
            stack.pop()
        total_scores.append(total_score)

print(sorted(total_scores)[len(total_scores) // 2])
