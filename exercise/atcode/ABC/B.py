x=int(input())
num=1
for i in range(2,x+1):
    num=num*i
    if num == x:
        print(i)
        break


    