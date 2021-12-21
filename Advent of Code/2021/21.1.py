from sys import stdin

pos = [int(line.split()[-1]) - 1 for line in stdin]
score = [0, 0]

die = 0
player = 0
roll_count = 0
while max(score) < 1000:
    die_sum = 0
    for i in range(3):
        die_sum += die + 1
        die = (die + 1) % 100
    pos[player] = (pos[player] + die_sum) % 10
    score[player] += pos[player] + 1
    player ^= 1
    roll_count += 3

print(min(score) * roll_count)
