from sys import exit

experiment_count = int(input())
bacteria_need = [int(_) for _ in input().split()]

bacteria_count = 1
for need in bacteria_need:
    bacteria_count *= 2
    if bacteria_count < need:
        print('error')
        exit(0)
    bacteria_count -= need

print(bacteria_count % (10 ** 9 + 7))
