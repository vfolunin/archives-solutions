sa = input()
sb = input()
 
a = -1
for i in range(len(sa)):
    if sa[i] != '0':
        a = max(a, int(sa[i:] + sa[:i]))

b = 10 ** 3000
for i in range(len(sb)):
    if sb[i] != '0':
        b = min(b, int(sb[i:] + sb[:i]))

print(a - b)
