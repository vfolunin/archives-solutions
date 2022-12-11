from sys import stdin


class Monkey:
    def __init__(self, lines):
        self.items = [int(_) for _ in lines[0].split(': ')[1].split(', ')]
        self.op = list(lines[1].split('= ')[1].split())
        self.mod = int(lines[2].split()[-1])
        self.to = [int(lines[i].split()[-1]) for i in range(4, 2, -1)]
        self.processed_items = 0

    def process_item(self, monkeys):
        a = self.items[0] if self.op[0] == 'old' else int(self.op[0])
        b = self.items[0] if self.op[2] == 'old' else int(self.op[2])
        value = a + b if self.op[1] == '+' else a * b
        value //= 3
        monkeys[self.to[value % self.mod == 0]].items.append(value)
        self.items.pop(0)
        self.processed_items += 1

    def process_items(self, monkeys):
        while self.items:
            self.process_item(monkeys)


lines = [line.strip() for line in stdin]
monkeys = []
for i in range(0, len(lines), 7):
    monkeys.append(Monkey(lines[i + 1:i + 6]))

for i in range(20):
    for monkey in monkeys:
        monkey.process_items(monkeys)

max_items = sorted(monkey.processed_items for monkey in monkeys)[-2:]
print(max_items[0] * max_items[1])
