import turtle

# 设置画布和画笔
screen = turtle.Screen()
screen.setup(1000, 350, 200, 200)
screen.bgcolor("white")
snake = turtle.Turtle()
snake.speed(2)  # 设置画笔速度
snake.pensize(20)  # 设置画笔粗细
snake.pencolor("purple")  # 设置笔迹颜色
#snake.color("red")  # 设置画笔和笔迹颜色


# 绘制蛇的身体
snake.penup()#抬起海龟
snake.goto(-300, 0)  # 移动到起始位置
snake.pendown()#放下
snake.seth(-40)#笔锋向下

for i in range(5):
    snake.circle(45, 80)  # 向右弯曲
    snake.circle(-45, 80)  # 向左弯曲

# 绘制蛇的头部
snake.circle(40, 80/2)
snake.forward(50)
snake.circle(16, 135)
snake.fd(40 * 2/3)

# 添加箭头图标
# snake.right(90)
# snake.forward(20)
# snake.right(135)
# snake.forward(30)
# snake.backward(30)
# snake.left(90)
# snake.forward(30)

# # 隐藏画笔
# snake.hideturtle()

# 显示图形
turtle.done()