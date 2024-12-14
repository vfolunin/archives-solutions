s = input()

a = []
id = 0
for i in range(len(s)):
    if i % 2:
        a.extend([-1] * int(s[i]))
    else:
        a.extend([id] * int(s[i]))
        id += 1

l, r = 0, len(a) - 1
while l <= r:
    if a[l] == -1:
        a[l], a[r] = a[r], a[l]
        while a[r] == -1:
            r -= 1
    l += 1

res = 0
for i in range(len(a)):
    if a[i] != -1:
        res += a[i] * i

print(res)
