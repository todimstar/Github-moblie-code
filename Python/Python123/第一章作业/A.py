# str = input().strip()
# print(str)
# op=None
# for c in "+-*/":
#     if c in str:
#         op=c
#         break

# jg = str.split(op)
# M=float(jg[0].strip())
# N=float(jg[1].strip())

# if jg:
#     if op=='+':
#         result = M+N
#     elif op=='-':
#         result = M-N
#     elif op=='*':
#         result = M*N
#     elif op=='/':
#         result = M/N
#     print("{:.2f}".format(result))

while True:
    try:
        # 读取输入
        str = input()
        print(str)
            
        # 使用eval函数直接计算表达式
        result = eval(str)
        
        # 格式化输出
        print("{:.2f}".format(result))
        
    except EOFError:
        break
