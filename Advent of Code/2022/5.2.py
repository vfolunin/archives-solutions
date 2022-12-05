from sys import stdin

lines = stdin.readlines()
empty_pos = lines.index('\n')
scheme, ops = lines[:empty_pos - 1], lines[empty_pos + 1:]

stacks = [[] for i in range(10)]
for line in scheme:
    for si, li in enumerate(range(1, len(line), 4)):
        if line[li] != ' ':
            stacks[si].append(line[li])

for i in range(len(stacks)):
    stacks[i].reverse()

for line in ops:
    tokens = line.split()
    count = int(tokens[1])
    source = int(tokens[3]) - 1
    destination = int(tokens[5]) - 1

    part = stacks[source][-count:]
    stacks[source] = stacks[source][:-count]
    stacks[destination].extend(part)

for stack in stacks:
    if stack:
        print(stack[-1], end='')
