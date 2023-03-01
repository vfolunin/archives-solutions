in_file = open('input.txt', 'r')
out_file = open('output.txt', 'w')

a = int(in_file.readline())
b = int(in_file.readline())

print(a // b, file=out_file)
print(a % b, file=out_file)
