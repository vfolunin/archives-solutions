from collections import deque
from math import lcm
from sys import stdin

modules = {}
for line in stdin:
    module_spec, children_names = line.strip().split(' -> ')
    if module_spec == 'broadcaster':
        type, name = 'b', module_spec
    elif module_spec[0] in '%&':
        type, name = module_spec[0], module_spec[1:]
    else:
        type, name = '', module_spec
    module = [type, children_names.split(', ')]
    if type == '%':
        module.append(0)
    modules[name] = module

sink_modules = set()
for name in modules:
    for child_name in modules[name][1]:
        if child_name not in modules:
            sink_modules.add(child_name)

for name in sink_modules:
    modules[name] = ['', []]

for name in modules:
    for child_name in modules[name][1]:
        if modules[child_name][0] == '&':
            if len(modules[child_name]) == 2:
                modules[child_name].append({})
                modules[child_name].append(0)
            modules[child_name][2][name] = 0

for name in modules:
    if 'rx' in modules[name][1]:
        nand_name = name

periods = {}
for name in modules:
    if nand_name in modules[name][1]:
        periods[name] = 0

q = deque()
i = 0

while 0 in periods.values():
    q.append(('button', 0, 'broadcaster'))
    i += 1

    while q:
        from_name, signal, name = q.popleft()
        if from_name in periods and signal == 1:
            periods[from_name] = i

        if modules[name][0] == 'b':
            for child_name in modules[name][1]:
                q.append((name, signal, child_name))
        elif modules[name][0] == '%':
            if signal == 0:
                modules[name][2] ^= 1
                for child_name in modules[name][1]:
                    q.append((name, modules[name][2], child_name))
        elif modules[name][0] == '&':
            modules[name][3] -= modules[name][2][from_name] == 1
            modules[name][2][from_name] = signal
            modules[name][3] += modules[name][2][from_name] == 1
            for child_name in modules[name][1]:
                q.append((name, modules[name][3] != len(modules[name][2]), child_name))

print(lcm(*periods.values()))
