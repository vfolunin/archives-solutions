diameter, height = [float(_) for _ in input().split()]

radius = diameter / 2
volume = 3.14 * radius * radius * height

print(f'{volume:.2f} cm^3')