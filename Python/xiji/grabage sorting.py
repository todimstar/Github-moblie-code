#案例设计：垃圾分类标语模板  
categories = {  
    "可回收": {"item":"玻璃、纸张、塑料","color":"蓝色"},  
    "有害": {"item":"电池、药品、油漆","color":"红色"},  
    "厨余": {"item":"剩饭、果皮、菜叶","color":"绿色"},  
    "其他": {"item":"污染纸张、尘土","color":"灰色"}  
}  

def sorting(garbage):
    for key, value in categories.items():
        items = value["item"].split("、")
        for item in items:
            if item in garbage:
                return f"【{garbage}】属于{key}垃圾，请投放至{value['color']}垃圾桶！\n{key}包括：{value['item']}" 
    return f"【{garbage}】暂未识别，请咨询社区工作人员！" 

# 用户输入垃圾类型，生成动态标语  
garbage = input("请输入垃圾名称（如‘塑料瓶’）：")  
advice = sorting(garbage)
print("\n=== 垃圾分类提示 ===\n" + advice)  
