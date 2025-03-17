def main():
    gril_name = input("Hi, gril! What your name?")
    age = 180
    vscode(gril_name,age)
    vscode()
    

def vscode(name="World!",nums=18):
    print("You,",name)
    print(f"lived {float(nums):.2f}")
    
main()
#这是可以的，因为直到12行main()调用时vscode()已经定义  