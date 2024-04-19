index = int(input())
index = (index - 1) * 2

s = ''
p = 2
while True:
    s += str(p)
    if len(s) > index + 1:
        print(s[index:index + 2])
        break
    p *= 2