# Get user input for alignment mode
alignment = input()

# Set the parameters
text = "PYTHON"
width = 30
fill_char = "*"

# Format the string based on the alignment input
if alignment == "左":
    result = text.ljust(width, fill_char)
elif alignment == "右":
    result = text.rjust(width, fill_char)
elif alignment == "中":
    result = text.center(width, fill_char)
else:
    result = "输入错误，请输入：左、右或中"

# Output the result
print(result)