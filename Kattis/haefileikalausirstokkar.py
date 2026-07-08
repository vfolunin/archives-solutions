bad_card_count = int(input())
bad_cards = set(input() for _ in range(bad_card_count))

deck_count = int(input())
for i in range(deck_count):
    is_bad = 0
    for j in range(6):
        is_bad |= input() in bad_cards
    print('Hæfileikalaust Drasl' if is_bad else 'Fínn Stokkur')