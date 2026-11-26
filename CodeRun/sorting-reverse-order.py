from json import loads
from requests import get

server = input()
port = input()
a = input()
b = input()

values = loads(get(f'{server}:{port}?a={a}&b={b}').text)
values = sorted([value for value in values if value > 0], reverse=True)

print(*values, sep='\n')