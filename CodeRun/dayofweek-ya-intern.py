from datetime import datetime
from sys import stdin

for line in stdin:
    print(datetime.strptime(line.strip(), '%d %B %Y').strftime('%A'))