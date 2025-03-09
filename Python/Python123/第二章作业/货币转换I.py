str = input()
cur = str[:3]
num = float(str[3:])

#复习输出格式化和type函数
# print(f"cur: {cur}, type: {type(cur)}")
# print(f"num: {num}, type: {type(num)}")


if cur == 'RMB':
    print("USD{:.2f}".format(num/6.78))
else:
    print("RMB{:.2f}".format(num*6.78))