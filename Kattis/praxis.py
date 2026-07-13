input()
a = [int(_) for _ in input().split()]

print('da komrad' if min(a) + 1 >= max(a) else 'ósvífinn kapítalisti')