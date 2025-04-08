user_input = input()
result = ""
for char in user_input:
    if char>='A' and char <='Z' or char>='a' and char<='z': 
        result += char
print(result)