# 获取输入字符串
s = input()

# 以减号(-)分割字符串
parts = s.split('-')

# 取首尾两段，用加号(+)连接
if len(parts) >= 2:  # 确保至少有两段
    result = parts[0] + '+' + parts[-1]
else:  # 如果只有一段或没有，直接输出该段
    result = s

# 输出结果
print(result)