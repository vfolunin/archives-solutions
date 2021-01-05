bill_number = 1
while 1:
    item_count, friend_count = [int(_) for _ in input().split()]
    if not item_count and not friend_count:
        break
    bill_sum = sum(int(input()) for _ in range(item_count))
    print('Bill #{} costs {}: each friend should pay {}\n'.format(bill_number, bill_sum, bill_sum // friend_count))
    bill_number += 1
