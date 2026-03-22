from collections import Counter

counter = Counter()
for i in range(int(input())):
    counter.update(input()[0])

print(counter.most_common(1)[0][0])