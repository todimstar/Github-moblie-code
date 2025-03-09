num = int(input())
str = "Hello World"
if num == 0:
    print(str)
elif num>0:#复习了for循环的步长用法
    for i in range(0,len(str),2):
        print(str[i:i+2])
else:
    for i in str:
        print(i)
