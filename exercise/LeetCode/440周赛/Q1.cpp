#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
提示：
n == fruits.length == baskets.length
1 <= n <= 100
1 <= fruits[i], baskets[i] <= 1000
*/

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int num=fruits.size(),baskets_len=baskets.size();
        int jg=0;
        vector<bool> used_baskets(baskets.size(),false);
        for(int i:fruits){
            for(int j=0;j<baskets_len;j++){
                if(used_baskets[j]){//已经装过水果
                    continue;
                }
                else if(baskets[j]>=i){//合适装且没装过
                    i=0;
                    used_baskets[j]=true;
                    break;
                }
                
            }if(i){//没放置
                jg++;
            }
        }
        return jg;
    }
};

int main() {
    Solution sol;
    
    // 测试用例1
    vector<int> fruits1 = {4,2,5};
    vector<int> baskets1 = {3,5,4};
    cout << "测试用例1：" << sol.numOfUnplacedFruits(fruits1, baskets1) 
         << "，预期：1" << endl;
    
    // 测试用例2
    vector<int> fruits2 = {5, 5, 5};
    vector<int> baskets2 = {2, 4, 3};
    cout << "测试用例2：" << sol.numOfUnplacedFruits(fruits2, baskets2) 
         << "，预期：3" << endl;
    
    // 测试用例3
    vector<int> fruits3 = {1, 2, 3, 4};
    vector<int> baskets3 = {4, 3, 2, 1};
    cout << "测试用例3：" << sol.numOfUnplacedFruits(fruits3, baskets3) 
         << "，预期：0" << endl;
    
    return 0;
}