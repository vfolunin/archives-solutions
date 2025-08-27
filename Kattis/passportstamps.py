trip_count, page_count = [int(_) for _ in input().split()]

stamped_count = 0
for i in range(trip_count):
    count = int(input())

    if stamped_count + i * (count - 1) + count > page_count:
        print(i)
        exit(0)

    stamped_count += count

print(trip_count)