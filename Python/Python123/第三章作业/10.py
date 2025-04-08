import math
n = int(input())
integral_result = 0.0
for x in range(1, n + 1):
    integral_result += (1 + 1 / x) ** x
integral_result = round(integral_result, 8)
print(f"{integral_result:.8f}")