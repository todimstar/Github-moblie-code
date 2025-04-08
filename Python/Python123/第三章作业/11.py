try:
    x = eval(input())
    result = pow(1/x, x)
    print("{:.4f}".format(result))
except NameError:
    print("请输入数字")
except SyntaxError:
    print("请输入数字")
except TypeError:
    print("请输入数字")
except:
    print("运算异常")