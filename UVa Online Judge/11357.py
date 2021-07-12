def solve():
    for clause in input().split('|'):
        literals = set(clause[1:-1].split('&'))
        satisfiable = True
        for i in range(26):
            var = chr(ord('a') + i)
            if var in literals and '~' + var in literals:
                satisfiable = False
                break
        if satisfiable:
            print('YES')
            return
    print('NO')


n = int(input())
for i in range(n):
    solve()
