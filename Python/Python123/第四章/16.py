for num in range(1000, 10000):
    if sum(int(digit)**4 for digit in str(num)) == num:
        print(num)