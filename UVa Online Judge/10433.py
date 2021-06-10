from sys import stdin

for line in stdin:
    line = line.strip()
    if (line not in ['0', '1'] and str(int(line) ** 2).endswith(line)):
        print('Automorphic number of {}-digit.'.format(len(line)))
    else:
        print('Not an Automorphic number.')
