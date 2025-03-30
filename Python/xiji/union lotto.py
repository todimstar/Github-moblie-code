import random

def union_lotto():
    #前区
    front = sorted(random.sample(range(1,34),6))
    #后区
    back = random.randint(1,16)
    print("本期双色球号码为：")
    print("前区：",front,end=", ")
    print("后区：",back)
    
if __name__ == "__main__":
    union_lotto()