from sys import stdin

program = ['from functools import lru_cache']
step = 1

for line in stdin:
    op, *args = line.split()
    
    if op == 'inp':
        if step > 1:
            program.append(f'\t\tr = step{step}(x, y, z)')
            program.append('\t\tif r:')
            program.append(f'\t\t\treturn w * 10 ** {15 - step} + r')
            program.append('\treturn 0')
        
        program.append('\n\n@lru_cache(maxsize=None)')
        program.append(f'def step{step}(cx, cy, cz):')
        program.append(f'\tfor w in range(1, 10):')
        program.append(f'\t\tx, y, z = cx, cy, cz')
        step += 1

    elif op == 'add':
        program.append(f'\t\t{args[0]} += {args[1]}')
    elif op == 'mul':
        program.append(f'\t\t{args[0]} *= {args[1]}')
    elif op == 'div':
        program.append(f'\t\t{args[0]} //= {args[1]}')
    elif op == 'mod':
        program.append(f'\t\t{args[0]} %= {args[1]}')
    else:
        program.append(f'\t\t{args[0]} = int({args[0]} == {args[1]})')

program.append('\t\tif not z:')
program.append('\t\t\treturn w')
program.append('\treturn 0')
program.append('\n\nprint(step1(0, 0, 0))')

print('\n'.join(program))
