def get_total_distance(coords, meet_coord):
    total_distance = 0
    for coord in coords:
        distance = abs(coord - meet_coord)
        total_distance += distance * (distance + 1) // 2
    return total_distance


coords = [int(_) for _ in input().split(',')]

print(min(get_total_distance(coords, coord) for coord in range(max(coords))))
