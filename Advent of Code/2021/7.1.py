coords = [int(_) for _ in input().split(',')]

coords.sort()
meet_coord = coords[len(coords) // 2]
total_distance = sum(abs(coord - meet_coord) for coord in coords)

print(total_distance)
