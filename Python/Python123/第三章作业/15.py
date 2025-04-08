money = eval(input())

# Calculate number of each bill needed
m50 = money // 50
remaining = money % 50
m5 = remaining // 5
m1 = remaining % 5

print("50yuan：", m50)
print("5yuan：", m5)
print("1yuan：", m1)