from collections import defaultdict
from math import prod
from sys import stdin


def is_star(a, y, x):
    return 0 <= y < len(a) and 0 <= x < len(a[0]) and a[y][x] == '*'


def get_neighbor_star_coords(a, y, x):
    for dy in range(-1, 2):
        for dx in range(-1, 2):
            if is_star(a, y + dy, x + dx):
                return y + dy, x + dx


def add_star_number(a, y, x, star_numbers):
    number, star_coords = 0, None
    while x < len(a[0]) and a[y][x].isdigit():
        number = number * 10 + int(a[y][x])
        coords = get_neighbor_star_coords(a, y, x)
        if coords is not None:
            star_coords = coords
        x += 1
    if star_coords is not None:
        star_numbers[star_coords].append(number)


a = [line.strip() for line in stdin]

star_numbers = defaultdict(list)
for y in range(len(a)):
    for x in range(len(a[0])):
        if a[y][x].isdigit() and (x == 0 or not a[y][x - 1].isdigit()):
            add_star_number(a, y, x, star_numbers)

print(sum(prod(values) for values in star_numbers.values() if len(values) == 2))
