input()
a = int(input())
b = int(input())

ancestors = set()
while a:
    ancestors.add(a)
    a //= 2

while b not in ancestors:
    b //= 2

print(b)
