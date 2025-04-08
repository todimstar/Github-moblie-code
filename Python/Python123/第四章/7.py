s = input("")  # 输入包含中文的字符串：
count = 0
for char in s:
    if 0x4E00 <= ord(char) <= 0x9FA5:
       count += 1
print(count)