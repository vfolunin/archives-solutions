value = int(input())
size = int(input())

print(sum(value ** int(input()) for _ in range(size)))