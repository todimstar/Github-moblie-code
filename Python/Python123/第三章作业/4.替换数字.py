num = input()
chinese_digits = "零一二三四五六七八九"
result = ""

for digit in num:
    result += chinese_digits[int(digit)]
    
print(result)