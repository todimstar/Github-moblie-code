from datetime import datetime

# 定义时间格式
time_format = "%Y年%m月%d日%H点%M分%S秒"

# 读取用户输入
input_str = input().strip()

try:
    # 按逗号分割输入字符串，获取两个时间字符串
    time1_str, time2_str = input_str.split(',')

    # 去除可能存在的空格
    time1_str = time1_str.strip()
    time2_str = time2_str.strip()

    # 将时间字符串解析为 datetime 对象
    time1 = datetime.strptime(time1_str, time_format)
    time2 = datetime.strptime(time2_str, time_format)

    # 计算时间差
    time_diff = abs(time1 - time2)

    # 提取时间差中的天数
    days_diff = time_diff.days

    # 输出结果
    print(days_diff)

except ValueError:
    # 捕获无效输入或格式错误
    print("输入的时间格式不正确")