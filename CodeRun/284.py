def read_time():
    h, m = [int(_) for _ in input().split(':')]
    return h * 60 + m


def write_time(t):
    print(f'{t // 60}:{t % 60:02d}')


t1 = read_time()
t2 = read_time()
delta = int(input())

t2 -= delta * 60
if t2 < 0:
    t2 += 24 * 60
if t2 < t1:
    t2 += 24 * 60

write_time(t2 - t1)