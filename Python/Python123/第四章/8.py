n = input()
sum_squares = 0
for digit in n:
    sum_squares += int(digit) ** 2
print(sum_squares)