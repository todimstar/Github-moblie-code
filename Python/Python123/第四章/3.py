total_sum = 0

while True:
    user_input = input()
    
    if user_input == "":  # If the input is empty, exit the loop
        break
    
    # Check if the input is a hexadecimal number
    if user_input.lower().startswith("0x"):
        total_sum += int(user_input, 16)  # Convert hex to decimal
    else:
        # Handle regular integers and floating point numbers
        total_sum += float(user_input)

# Print as int if it's a whole number, otherwise as float
if total_sum == int(total_sum):
    print(int(total_sum))
else:
    print(total_sum)