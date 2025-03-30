import math
'''
自定义进步率和退步率，分别输出365天后的结果
'''

day_up = float(input("请输入每天进步率%：")) / 100
day_down = float(input("请输入每天退步率%：")) / 100
result_up = math.pow((1 + day_up), 365)
result_down = math.pow((1 - day_down), 365)
print("每天进步：{:.2f}%，365天后的结果：{:.2f}".format(day_up*100,result_up))
print("每天退步：{:.2f}%，365天后的结果：{:.2f}".format(day_down*100,result_down))