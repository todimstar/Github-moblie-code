def fun(text, shift=3):
    result = ""
    for char in text:
        if 'a' <= char <= 'z' or 'A' <= char <= 'Z':
            if char.islower(): 
                result += chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
            else:
                result += chr((ord(char) - ord('A') + shift) % 26 + ord('A'))
        else:
            result += char
    return result
text = input()
jg = fun(text)
print(jg)
