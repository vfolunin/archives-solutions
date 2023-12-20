from collections import deque
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

q = deque()
signal_count = [0, 0]

for i in range(1000):
    q.append(('button', 0, 'broadcaster'))

    while q:
        from_name, signal, name = q.popleft()
        signal_count[signal] += 1

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

print(signal_count[0] * signal_count[1])