_, x = [int(_) for _ in input().split()]
coeff = [int(_) for _ in input().split()]

print(sum(coeff[i] * x ** i for i in range(len(coeff))))
