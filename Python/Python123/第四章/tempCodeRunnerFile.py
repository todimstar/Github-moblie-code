# 打印九九乘法表
for b in range(1, 10):  # 从1到9
    for a in range(1, b + 1):  # 从1到b
        product = a * b
        print(a)
        print("*")
        print(b)
        print("=")
        print(product)
        # 根据乘积位数添加适当的空格
        if product < 10:
            print("  ")
        else:
            print(" ")