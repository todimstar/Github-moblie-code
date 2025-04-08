import random

n = input()
random.seed(int(n))
s = 'ABCDEFGHIJ0123456789'
result = ''.join(random.choice(s) for _ in range(6))
print(result)