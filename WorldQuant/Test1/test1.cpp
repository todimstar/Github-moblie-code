#include <iostream>
#include <vector>
#include <string>
int main() {
    // 定义数据字段列表
    std::vector<std::string> data_fields = {
        "fnd17_oxlcxspebq", "fnd17_shsoutbs", "fnd28_value_05191q", "fnd28_value_05192q",
        "fnd28_value_05301q", "fnd28_value_05302", "fnd17_pehigh", "fnd17_pelow",
        "fnd17_priceavg150day", "fnd17_priceavg200day", "fnd17_priceavg50day",
        "fnd17_pxedra", "fnd17_tbea", "fnd28_newa3_value_18191a", "fnd28_newa3_value_18198a",
        "fnd28_value_02300a", "mdl175_ebitda", "mdl175_pain"
    };
    // 初始化组合计数器
    int total_combinations = 0,data_fields_size = data_fields.size();
    // 遍历所有可能的A和B组合
    for (size_t i = 0; i < data_fields_size; ++i) {
        for (size_t j = i + 1; j < data_fields_size; ++j) {
            std::string A = data_fields[i];
            std::string B = data_fields[j];
            if(A!=B){// 符合条件则生成Alpha表达式
                std::string alpha_expression = "ts_regression(ts_zscore(" + A + ", 500), ts_zscore(" + B + ", 500), 500)";
                std::cout << alpha_expression << std::endl;
                total_combinations++;
            }
        }
    }
    std::cout << "Total combinations: " << total_combinations << std::endl;// 输出总组合数
    return 0;
}