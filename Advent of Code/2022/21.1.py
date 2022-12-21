from collections import defaultdict
from sys import stdin


def eval(tree, v):
    if len(tree[v]) == 1:
        return tree[v][0]

    if tree[v][1] == '+':
        return eval(tree, tree[v][0]) + eval(tree, tree[v][2])
    elif tree[v][1] == '-':
        return eval(tree, tree[v][0]) - eval(tree, tree[v][2])
    elif tree[v][1] == '*':
        return eval(tree, tree[v][0]) * eval(tree, tree[v][2])
    else:
        return eval(tree, tree[v][0]) // eval(tree, tree[v][2])


tree = defaultdict(list)
for line in stdin:
    v, op = line.strip().split(': ')
    if ' ' in op:
        tree[v] = op.split()
    else:
        tree[v] = [int(op)]

print(eval(tree, 'root'))
