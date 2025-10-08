stack = []
while 1:
    token = input()
    if token == 'quit':
        break
    elif token[-1].isdigit():
        stack.append(int(token))
    elif token == 'print':
        print(stack[-1])
    elif token == 'dup':
        stack.append(stack[-1])
    elif token == 'pop':
        stack.pop()
    else:
        b = stack.pop()
        a = stack.pop()
        if token == 'swap':
            stack.append(b)
            stack.append(a)
        elif token == '+':
            stack.append(a + b)
        elif token == '-':
            stack.append(a - b)
        elif token == '*':
            stack.append(a * b)
        elif token == '/':
            stack.append(a // b)
        else:
            stack.append(a ** b)
