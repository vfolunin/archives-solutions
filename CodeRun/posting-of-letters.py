origin = int(input().split()[0])
a = sorted([int(_) for _ in input().split()])

if origin <= a[0]:
    print(a[-1] - origin)
elif a[-1] <= origin:
    print(origin - a[0])
else:
    print(a[-1] - a[0] + min(origin - a[0], a[-1] - origin))