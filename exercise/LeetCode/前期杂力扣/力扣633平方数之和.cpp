/*力扣633平方数之和，https://leetcode.cn/problems/sum-of-square-numbers/submissions/537790620/
*/

//1.0  3ms
typedef long long ll;//不改变输入数据类型的强转
class Solution {
public:
    bool judgeSquareSum(int c) {
        int a=0,b=(int)sqrt(c);
        while(a<=b){
            if((ll)(a*a)+(ll)(b*b)==(ll)c)return true;
            else if((ll)(a*a)+(ll)(b*b)<(ll)c){
                a++;
            }else{
                b--;
            }
        }return false;
    }
};

//1.1  0ms 内存甚至少了 
typedef long long ll;
class Solution {
public:
    bool judgeSquareSum(ll c) {//直接全ll了 
        ll a=0,b=(int)sqrt(c);
        while(a<=b){
            if((a*a)+(b*b)==c)return true;
            else if((a*a)+(b*b)<c){
                a++;
            }else{
                b--;
            }
        }return false;
    }
};
