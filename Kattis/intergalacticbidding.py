participant_count, target_sum = [int(_) for _ in input().split()]

bets = []
for i in range(participant_count):
    name, bet = input().split()
    bets.append((int(bet), name))
bets.sort(reverse=True)

winners = []
for bet, name in bets:
    if target_sum >= bet:
        target_sum -= bet
        winners.append(name)

if target_sum:
    print(0)
else:
    print(len(winners))
    for name in winners:
        print(name)
