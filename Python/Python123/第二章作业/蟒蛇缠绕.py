#e2.2DrawPython.py
from turtle import *
setup(1000, 350, 200, 200)
penup()
fd(-250)
pendown()
pensize(25)
pencolor("purple")
seth(-40)
for i in range(5):
    circle(45, 80)
    circle(-45, 80)
circle(40, 80/2)
fd(40)
circle(16, 135)
fd(40 * 2/3)