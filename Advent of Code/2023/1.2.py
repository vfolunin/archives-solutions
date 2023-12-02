from sys import stdin


def get_first_digit(s, range):
    digit_names = 'one two three four five six seven eight nine'.split()
    for i in range:
        if line[i].isdigit():
            return int(line[i])
        for digit_index, digit_name in enumerate(digit_names):
            if line[i:].startswith(digit_name):
                return digit_index + 1


res = 0
for line in stdin:
    res += get_first_digit(line, range(len(line))) * 10
    res += get_first_digit(line, range(len(line) - 1, -1, -1))

print(res)
