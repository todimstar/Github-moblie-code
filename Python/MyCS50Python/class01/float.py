a = float(input())
b = float(input())

#保留位数 
# 1.round()  并四舍五入
z = round(a+b)  # round(number[, ndigits])四舍五入可指定保留位数函数

#2.f"{x:.2f}"
print(f"{z:.2f}")

# f"{:}" 的更多用法, 1,000,000格式输出
print(f"{z:,}")