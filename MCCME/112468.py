in_file = open('input.txt', 'r')
out_file = open('output.txt', 'w')

n = int(in_file.readline())

l, r = 1, n + 1
while l + 1 < r:
    m = (l + r) // 2
    if m * m <= n:
        l = m
    else:
        r = m

print(l, file=out_file)
print(n - l * l, file=out_file)
