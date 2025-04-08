def dayup_factor(factor):
    result = 1.0
    for i in range(365):
        if i % 7 in [0, 6]:  # 周末
            result *= 0.99
        else:  # 工作日
            result *= (1 + factor)
    return result
target = pow(1.01, 365)
factor = 0.01
#粗糙暴力遍历，不能二分，二分就是0.018了
while dayup_factor(factor) < target:
    factor += 0.001
print(f"工作日的努力参数是: {factor:.3f}")
