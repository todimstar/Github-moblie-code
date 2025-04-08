n = int(input())
is_prime = True

# 1 is not prime
if n <= 1:
    is_prime = False
else:
    # Check if n is divisible by any number from 2 to sqrt(n)
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            is_prime = False
            break

print("True" if is_prime else "False")