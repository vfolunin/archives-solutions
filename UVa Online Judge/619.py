def solve():
    line = input()

    if line == '*':
        return 0

    if line.isalpha():
        s, n = line, 0
        for c in line:
            n = n * 26 + ord(c) - ord('a') + 1
    else:
        s, n = '', int(line)
        m = n - 1
        while m >= 0:
            s += chr(ord('a') + m % 26)
            m = m // 26 - 1
        s = s[::-1]

    print('{:22}{:,}'.format(s, n))
    return 1


while solve():
    pass
