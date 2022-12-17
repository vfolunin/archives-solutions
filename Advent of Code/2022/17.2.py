class Shape:
    def __init__(self, field, type):
        shapes = ['@@@@', '.@.|@@@|.@.', '@@@|..@|..@', '@|@|@|@', '@@|@@']
        self.a = [[c for c in row] for row in shapes[type].split('|')]
        self.y = field.get_height() + 3
        self.x = 2

    def fits(self, field):
        for sy in range(len(self.a)):
            fy = self.y + sy
            for sx in range(len(self.a[sy])):
                fx = self.x + sx
                if self.a[sy][sx] == '@' and (
                        fy < 0 or fy >= len(field.a) or fx < 0 or fx >= len(field.a[fy]) or field.a[fy][fx] == '#'):
                    return 0
        return 1

    def move_left(self, field):
        self.x -= 1
        if not self.fits(field):
            self.x += 1

    def move_right(self, field):
        self.x += 1
        if not self.fits(field):
            self.x -= 1

    def move_down(self, field):
        self.y -= 1
        if not self.fits(field):
            self.y += 1
            return 0
        return 1

    def apply(self, field):
        for sy in range(len(self.a)):
            fy = self.y + sy
            for sx in range(len(self.a[sy])):
                fx = self.x + sx
                if self.a[sy][sx] == '@':
                    field.a[fy][fx] = '#'
                    while len(field.a) < self.y + sy + 10:
                        field.a.append(['.' for x in range(7)])

    def print(self, field):
        for fy in range(len(field.a) - 1, -1, -1):
            sy = fy - self.y
            for fx in range(len(field.a[fy])):
                sx = fx - self.x
                if 0 <= sy < len(self.a) and 0 <= sx < len(self.a[sy]) and self.a[sy][sx] == '@':
                    print('@', end='')
                else:
                    print(field.a[fy][fx], end='')
            print()


class Field:
    def __init__(self):
        self.a = [['.' for x in range(7)] for y in range(10)]

    def get_height(self):
        for y in range(len(self.a) - 1, -1, -1):
            if '#' in self.a[y]:
                return y + 1
        return 0


shifts = input()
shift_index = 0
field = Field()

xs = []
additional_height = 0
seen = {}
shape_count = 0

while shape_count < 10 ** 12:
    shape = Shape(field, shape_count % 5)
    while 1:
        if shifts[shift_index] == '<':
            shape.move_left(field)
        else:
            shape.move_right(field)
        shift_index = (shift_index + 1) % len(shifts)
        if not shape.move_down(field):
            shape.apply(field)
            break

    xs.append(shape.x)
    if additional_height == 0 and shape_count >= 10:
        last_xs = tuple(xs[-10:])
        if last_xs in seen:
            prev_shape_count, prev_height = seen[last_xs]
            left_shape_count = 10 ** 12 - shape_count
            period = shape_count - prev_shape_count
            cycle_count = left_shape_count // period
            delta_height = field.get_height() - prev_height
            additional_height = delta_height * cycle_count
            shape_count += period * cycle_count
        else:
            seen[last_xs] = shape_count, field.get_height()

    shape_count += 1

print(field.get_height() + additional_height)
