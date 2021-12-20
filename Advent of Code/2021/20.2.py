from sys import stdin


def get_code(img, cy, cx, base):
    code = 0
    for y in range(cy - 1, cy + 2):
        for x in range(cx - 1, cx + 2):
            code *= 2
            if 0 <= y < len(img) and 0 <= x < len(img[0]):
                code += img[y][x]
            else:
                code += base
    return code


def update(img, algo, base):
    next_img = []
    for y in range(-1, len(img) + 1):
        next_img.append([])
        for x in range(-1, len(img[0]) + 1):
            next_img[-1].append(algo[get_code(img, y, x, base)])
    return next_img


lines = [line.strip() for line in stdin.readlines()]
algo = [c == '#' for c in lines[0]]
img = [[c == '#' for c in line] for line in lines[2:]]

base = False
for i in range(50):
    img = update(img, algo, base)
    base = algo[-1] if base else algo[0]

print(sum(sum(line) for line in img))
