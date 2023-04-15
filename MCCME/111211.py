[[0 if y == x or y + x == n - 1 else (1 if y + x < n - 1 else 2) if y < x else (3 if y + x > n - 1 else 4) for x in range(n)] for y in range(n)]
