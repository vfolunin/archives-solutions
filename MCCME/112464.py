in_file = open('input.txt', 'r')
out_file = open('output.txt', 'w')

a = int(in_file.readline())
b = int(in_file.readline())

print((a + b) // 2, end='', file=out_file)
if (a + b) % 2:
    print('.5', file=out_file)
