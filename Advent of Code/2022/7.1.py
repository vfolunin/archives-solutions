from collections import defaultdict
from sys import stdin


def rec(graph, path):
    global dir_size
    for dir in graph[path]:
        dir_size[path] += rec(graph, path + '/' + dir)
    return dir_size[path]


lines = [line.strip() for line in stdin]
line_index = 0

path = []
graph = defaultdict(list)
dir_size = defaultdict(int)

while line_index < len(lines):
    tokens = lines[line_index].split()
    if tokens[1] == 'cd':
        if tokens[2] == '..':
            path.pop()
        else:
            path.append(tokens[2])
        line_index += 1
    else:
        next_index = line_index + 1
        while next_index < len(lines) and not lines[next_index].startswith('$'):
            tokens = lines[next_index].split()
            if tokens[0] == 'dir':
                graph['/'.join(path)].append(tokens[1])
            else:
                dir_size['/'.join(path)] += int(tokens[0])
            next_index += 1
        line_index = next_index

rec(graph, '/')

res = 0
for path, size in dir_size.items():
    if size <= 100000:
        res += size
print(res)
