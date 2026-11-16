size = int(input())
a = [input() for i in range(size)]

for i in range(len(a)):
    if 'rest' in a[i]:
        a[i] = '😎'
    elif 'leg' in a[i]:
        a[i] = '🦵'
    else:
        a[i] = '💪'

for i in range(31):
    print(a[i % len(a)], end='')
    if i % 7 == 6:
        print()