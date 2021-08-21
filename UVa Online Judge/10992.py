def solve(test):
    y = int(input())

    if not y:
        return 0

    ghosts = [('Tanveer Ahsan', 2), ('Shahriar Manzoor', 5), ('Adrian Kugel', 7), ('Anton Maydell', 11),
              ('Derek Kisman', 15), ('Rezaul Alam Chowdhury', 20), ('Jimmy Mardell', 28), ('Monirul Hasan', 36)]

    if test:
        print()

    print(y)
    has_ghost = 0

    for name, mod in ghosts:
        if y >= 2148 and (y - 2148) % mod == 0:
            has_ghost = 1
            print('Ghost of {}!!!'.format(name))

    if y >= 2148 and (y % 400 == 0 or y % 4 == 0 and y % 100):
        has_ghost = 1
        print('Ghost of K. M. Iftekhar!!!')

    if not has_ghost:
        print('No ghost will come in this year')
    return 1


i = 0
while solve(i):
    i += 1
