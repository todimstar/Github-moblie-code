x = input().strip(',')#strip()去掉字符串前后的指定字符
print(x)
print(x.split(' '))#split()分割字符串

print(round(2132 + 0.2,-3))#四舍五入,round(num,k)表示保留k位小数,默认0位小数且不会有.0
#True是1，False是0

x=1
def outer():
    x = 10
    def inner():
        nonlocal x
        x = 20
    inner()
    print(x)  # 输出 20
outer()
print(x)  # 输出 1