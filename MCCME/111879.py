index = int(input()) - 1

l, r = 0, 1
while r * (r + 1) // 2 <= index:
    r *= 2

while l + 1 < r:
    m = l + (r - l) // 2
    if m * (m + 1) // 2 <= index:
        l = m
    else:
        r = m

prev_blocks = l
index -= prev_blocks * (prev_blocks + 1) // 2
block_start = prev_blocks * prev_blocks + 1

print(block_start + index * 2)
