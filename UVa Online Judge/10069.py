from collections import defaultdict

def solve():
    text = input()
    pattern = input()

    pos = defaultdict(list)
    for i in range(len(pattern)):
        pos[pattern[i]].append(i)

    ss_count = [0 for _ in range((len(pattern) + 1))]
    ss_count[0] = 1

    for c in text:
        next_ss_count = ss_count[:]
        for p in pos[c]:
            next_ss_count[p + 1] += ss_count[p]
        ss_count = next_ss_count[:]

    print(ss_count[len(pattern)])


for _ in range(int(input())):
    solve()
