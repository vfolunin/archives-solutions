from collections import defaultdict
from sys import stdin


def sign(value):
    if value < 0:
        return -1
    elif value == 0:
        return 0
    else:
        return 1


def eval(tree, v, h):
    if len(tree[v]) == 1:
        return h if v == 'humn' else tree[v][0]

    if tree[v][1] == '+':
        return eval(tree, tree[v][0], h) + eval(tree, tree[v][2], h)
    elif tree[v][1] == '-':
        return eval(tree, tree[v][0], h) - eval(tree, tree[v][2], h)
    elif tree[v][1] == '*':
        return eval(tree, tree[v][0], h) * eval(tree, tree[v][2], h)
    elif tree[v][1] == '/':
        return eval(tree, tree[v][0], h) // eval(tree, tree[v][2], h)
    else:
        return sign(eval(tree, tree[v][0], h) - eval(tree, tree[v][2], h))


tree = defaultdict(list)
for line in stdin:
    v, op = line.strip().split(': ')
    if ' ' in op:
        tree[v] = op.split()
    else:
        tree[v] = [int(op)]
tree['root'][1] = '?'

l, r = 0, 10 ** 18
l_value = eval(tree, 'root', l)
while l + 1 < r:
    m = l + (r - l) // 2
    if eval(tree, 'root', m) == l_value:
        l = m
    else:
        r = m

print(r)
