import re

def simulate(vx, vy, tx1, ty1, tx2, ty2):
    x, y, max_y = 0, 0, 0
    while 1:
        x += vx
        y += vy
        max_y = max(max_y, y)
        if tx1 <= x <= tx2 and ty1 <= y <= ty2:
            return max_y

        if vx > 0:
            vx -= 1
        elif vx < 0:
            vx += 1
        vy -= 1
        if y < ty1 and vy < 0:
            return None


tx1, tx2, ty1, ty2 = [int(_) for _ in re.findall('([-+]?[0-9]+)', input())]

max_y = 0
for vx in range(-200, 201):
    for vy in range(-200, 201):
        y = simulate(vx, vy, tx1, ty1, tx2, ty2)
        if y is not None:
            max_y = max(max_y, y)

print(max_y)
