import math
import cmath

# 获取用户输入的整数
a = int(input())

# 计算平方根 (使用cmath处理负数)
if a >= 0:
    result = math.sqrt(a)
    result_str = f"{result:.3f}"
else:
    # 对于负数，使用cmath计算复数平方根
    result = cmath.sqrt(a)
    # 复数格式：实部+虚部j
    result_str = f"{result.real:.3f}{result.imag:+.3f}j"

# 输出结果，宽度30个字符，右对齐，加号填充
print(f"{result_str:+>30}")