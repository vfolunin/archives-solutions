size = int(input())

emails = set()
for i in range(size):
    user, domain = input().split('@')
    user = user.split('-')[0].replace('.', '')
    domain = '.'.join(domain.split('.')[:-1])
    emails.add((user, domain))

print(len(emails))