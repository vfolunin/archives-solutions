def get_hash(s):
    res = 0
    for c in s:
        res = (res + ord(c)) * 17 % 256
    return res


print(sum([get_hash(s) for s in input().split(',')]))
