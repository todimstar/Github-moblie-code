n = input()  # 输入一个数
result = 2 ** int(n)  # 计算2的N次幂
last_three_digits = result % 1000  # 获取结果的后3位
print(f"{last_three_digits:03d}")  # 格式化为3位数，不足的用0填充