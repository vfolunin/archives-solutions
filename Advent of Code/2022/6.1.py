line = input()

for i in range(3, len(line)):
    if len(set(line[i - 3:i + 1])) == 4:
        print(i + 1)
        break
