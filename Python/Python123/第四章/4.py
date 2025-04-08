import random

# Get input and parse it
input_str = input()
nums = input_str.split(',')
num1 = int(nums[0])
num2 = int(nums[1])

# Calculate sum and set as seed
seed_value = num1 + num2
random.seed(seed_value)

# Generate 20 random integers and convert to characters
result = ""
for _ in range(20):
    rand_int = random.randint(32, 127)
    result += chr(rand_int)

# Output result
print(result)