import sys

def main():
    try:
        H = float(input("请输入身高（米）："))
        if H <= 0:
            print("身高必须大于0")
            return 1
            
        W = float(input("请输入体重（千克）："))
        if W <= 0:
            print("体重必须大于0")
            return 2
            
        BMI = W / H ** 2
        
        if BMI < 18.5:
            print("BMI指数为：{:.2f}，体重过轻".format(BMI))
        elif BMI < 24:
            print("BMI指数为：{:.2f}，正常范围".format(BMI))
        elif BMI < 28:
            print("BMI指数为：{:.2f}，体重过重".format(BMI))
        elif BMI < 30:
            print("BMI指数为：{:.2f}，轻度肥胖".format(BMI))
        elif BMI < 35:
            print("BMI指数为：{:.2f}，中度肥胖".format(BMI))
        else:
            print("BMI指数为：{:.2f}，重度肥胖".format(BMI))
        
        return 0  # 正常退出
        
    except ValueError as e:
        print("输入错误：请输入有效的数字")
        raise ValueError from e     #抛出异常，保留异常链，会显示双回溯链
    except Exception as e:
        print(f"程序出错：{e}")
        return 4

if __name__ == "__main__":
    exit_code = main()
    sys.exit(exit_code)
