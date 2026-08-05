size = int(input())

trib = [0, 1, 0]
for i in range(size):
    trib.append(sum(trib[-3:]))

    print(trib[-1])
