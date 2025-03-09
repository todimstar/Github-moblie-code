import turtle

# 设置画布和画笔
screen = turtle.Screen()
screen.bgcolor("white")
snake = turtle.Turtle()
snake.speed(1)  # 设置画笔速度
snake.pensize(20)  # 设置画笔粗细
snake.color("purple")  # 设置画笔颜色

# 绘制蛇的身体
snake.penup()
snake.goto(-300, 0)  # 移动到起始位置
snake.pendown()

for i in range(5):
    snake.circle(50, 45)  # 向右弯曲
    snake.circle(-50, 45)  # 向左弯曲

# 绘制蛇的头部
snake.circle(50, 45)
snake.forward(50)

# 添加箭头图标
snake.right(90)
snake.forward(20)
snake.right(135)
snake.forward(30)
snake.backward(30)
snake.left(90)
snake.forward(30)

# 隐藏画笔
snake.hideturtle()

# 显示图形
turtle.done()