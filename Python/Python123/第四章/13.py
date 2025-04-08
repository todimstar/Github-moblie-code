# 枚举公鸡、母鸡和小鸡的数量
for x in range(0, 21):  # 公鸡最多 20 只
    for y in range(0, 34):  # 母鸡最多 33 只
        z = 100 - x - y  # 小鸡数量
        if z % 3 == 0 and 15 * x + 9 * y + z // 3 == 300:  # 确保小鸡数量是3的倍数
            print(f"公鸡: {x}")
            print(f"母鸡: {y}")
            print(f"小鸡: {z}\n")