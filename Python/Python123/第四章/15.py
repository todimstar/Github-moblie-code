m = input("请输入对齐模式：")
s = "PYTHON"
if  m =="右":
    m = ">"
elif  m =="中":
    m = "^"
else:
    m = "<"
print("{:*{align}30}".format(s, align=m))