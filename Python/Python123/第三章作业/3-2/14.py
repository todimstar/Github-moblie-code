a, b, c = eval(input())
p = (a+b+c)/2
area = pow(p * (p-a)*(p-b)*(p-c), 0.5)
print("{:.2f}".format(area))