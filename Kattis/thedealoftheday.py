card_count = [int(_) for _ in input().split()]
deal_count = int(input())

ways = [[0 for deal in range(deal_count + 1)] for card in range(len(card_count))]
for card in range(len(card_count)):
    ways[card][1] = card_count[card]
    for deal in range(2, deal_count + 1):
        for prev_card in range(card):
            ways[card][deal] += ways[prev_card][deal - 1] * card_count[card]

print(sum(ways[card][deal_count] for card in range(len(card_count))))
