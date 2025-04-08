# 设置正确的用户名和密码
correct_username = "Kate"
correct_password = "666666"

# 给用户三次登录机会
success = False
for i in range(3):
    username = input()
    password = input()
    
    # 检查用户名和密码是否正确
    if username == correct_username and password == correct_password:
        print("登录成功！")
        success = True
        break

# 如果三次尝试后仍未成功登录
if not success:
    print("3次用户名或者密码均有误！退出程序。")