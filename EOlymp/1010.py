a = input()
b = input()
c = input()

for base in range(int(max(a + b + c + '1')) + 1, 37):
    if int(a, base) + int(b, base) == int(c, base):
        print(base)
        break
else:
    print(0)