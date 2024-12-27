#include <iostream>
#include <cmath>
#include <string>
#include <unordered_set>
using namespace std;

// 查找拼接平方数
void findSplitSquares(int a, int b) {
    // 预处理所有可能的平方数
    unordered_set<int> squares;
    for (int i = 1; i * i <= b; ++i) {
        squares.insert(i * i); // 将平方数插入哈希集合
    }

    // 遍历区间内所有数
    for (int num = a; num <= b; ++num) {
        if(squares.count(num)){
            string strNum = to_string(num); // 转换成字符串方便分割
            int len = strNum.length();

            // 遍历所有可能的拆分位置
            for (int i = 1; i < len; ++i) {
                string leftPart = strNum.substr(0, i); // 左部分
                string rightPart = strNum.substr(i);  // 右部分

                // 检查右部分是否全是前导零
                if (rightPart.find_first_not_of('0') == string::npos) continue;

                // 转换字符串为整数
                int left = stoi(leftPart);
                int right = stoi(rightPart);

                // 检查两部分是否都是平方数
                if (squares.count(left) && squares.count(right)) {
                    cout << num << endl; // 输出结果
                    break; // 只需要输出一次，跳出当前数的循环
                }
            }
        }
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    findSplitSquares(a, b);
    return 0;
}
