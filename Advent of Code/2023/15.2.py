def get_hash(s):
    res = 0
    for c in s:
        res = (res + ord(c)) * 17 % 256
    return res


def insert(box, label, factor):
    for i in range(len(box)):
        if box[i][0] == label:
            box[i][1] = factor
            return
    box.append([label, factor])


def erase(box, label):
    for i in range(len(box)):
        if box[i][0] == label:
            box.pop(i)
            return


boxes = [[] for i in range(256)]

for s in input().split(','):
    if '=' in s:
        label, factor = s.split('=')
        insert(boxes[get_hash(label)], label, int(factor))
    else:
        label = s[:-1]
        erase(boxes[get_hash(label)], label)

res = 0
for i in range(len(boxes)):
    for j in range(len(boxes[i])):
        res += (i + 1) * (j + 1) * boxes[i][j][1]
print(res)
