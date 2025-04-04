import turtle as t
t.pensize(2)
for i in range(___________):
    t.fd(150)
    t.left(___________)
    t.pensize(2)
    for i in range(8):  # 循环8次，因为八边形有8条边
        t.fd(150)       # 向前移动150单位长度
        t.left(45)      # 每次左转45度(360/8=45度)，画出八边形的一个角

    # 原理说明：
    # 1. turtle库是Python的一个绘图库，模拟一只乌龟在屏幕上爬行进行绘图
    # 2. t.pensize(2)设置画笔粗细为2
    # 3. 八边形有8个边，所以循环8次
    # 4. 每次循环：
    #    - t.fd(150)让乌龟向前移动150单位，画出一条边
    #    - t.left(45)让乌龟左转45度(因为八边形的内角和为360度，每个角为360/8=45度)
    # 5. 循环结束后，乌龟刚好回到起点，形成一个完整的八边形
