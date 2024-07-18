target_product = int(input())

l, r, product = 2, 2, 2
while product != target_product:
    while product < target_product:
        r += 1
        product *= r
    while product > target_product:
        product //= l
        l += 1

print(l, r)