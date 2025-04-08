for char in s:
    if char in ",?":  # Check if the character is a punctuation mark
        m += 1
    elif '\u4e00' <= char <= '\u9fff':  # Check if the character is a Chinese character
        n += 1