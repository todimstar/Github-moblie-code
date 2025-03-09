input_str = input()
#复习了字符串的切片
if input_str[-1:] in ['C','c']:
    C = float(input_str[:-1])
    F = C*1.8+32
    print("{:.2f}F".format(F))
elif input_str[-1:] in ['F','f']:
    F = float(input_str[:-1])
    C = (F-32)/1.8
    print("{:.2f}C".format(C))
else:
    print("输入格式错误")
    exit()