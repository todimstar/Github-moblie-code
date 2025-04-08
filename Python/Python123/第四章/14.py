for i in range(1, 10):  # 外层循环控制行数
    for j in range(1, i + 1):  # 内层循环控制每行的列数
        print(f"{j}*{i}={i*j:<2}", end=" ")  # 使用 `<2` 左对齐，确保两位数对齐
    print()  # 换行