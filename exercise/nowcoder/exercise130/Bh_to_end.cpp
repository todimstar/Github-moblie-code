#include <iostream>//算法注释：贪心算法或模拟，心得：注意L,R都是负数直接+	，题目网址：https://ac.nowcoder.com/acm/contest/93002/B
using namespace std;//跟atcode丰田赛C_sum=0类似

#define int long long
const int N = 1e5 + 10;
int n, k, h, L, R;
int a[N];

bool solve() {
    // 边界条件判断，判断均分的范围是否可行
    if (L*k <= -h && -h <= R*k) {//l*k--<=--(-h)--<=--(r*k)
        
        for(int i=0;i<n;i++)a[i]=L;//全L
        
        int cha = abs(h+L*k);//看L*k多减了多少
        for(int i=0;i<n;i++){
            if(cha >=R-L){//对多减的补偿R-L
                a[i] = R;
                cha-=R-L;
            }else{//不需要补偿R-L，补偿cha
                a[i] = L+cha;//也是最后一次了，这i正好使到0
                break;//之后随便了
            }
        }return true;
        
    }
    else{
        return false;        //左边界包能减完,右边界最多只能到正好减完
    }
    
}
signed main() {
    cin >> n >> k >> h >> L >> R;

    if (!solve()) {
        cout << "impossible" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}



// #include <iostream>//算法注释：贪心算法或模拟，心得：这题没想通为什么要倒拿，为什么R只用用一次	，题目网址：https://ac.nowcoder.com/acm/contest/93002/B
// using namespace std;//问问万能的群u

// #define int long long
// const int N = 1e5 + 10;
// int n, k, h, L, R;
// int a[N];

// bool solve() {
//     // 边界条件判断，判断均分的范围是否可行
//     if (h+R*k<0 || h + L * k > 0) {//唯一利用到R的地方，但是之后就没根据L到R判断均分的是否在范围了
//         return false;
//     }

//     // 计算每一步的损失值
//     int avg = h / k;    //均分，1.为什么h+R*k<0可以保证avg在L到R内？
//     int remainder =k-h % k;    //2.奇怪的倒拿h%k才能过


//     // 处理每一步
//     for (int i = 0; i < k; i++) {
//         if (remainder > 0) {
//             a[i] = -(avg);  // 前几步因为倒拿，是均分
//             remainder--;
//         } else {
//             a[i] = -avg-1;  // 因为倒拿才能过，是后续-1
//         }
//     }

//     // 剩余的房间设为任意符合范围的值
//     for (int i = k; i < n; i++) {
//         a[i] = L;
//     }

//     return true;
// }

// signed main() {
//     cin >> n >> k >> h >> L >> R;

//     if (!solve()) {
//         cout << "impossible" << endl;
//     } else {
//         for (int i = 0; i < n; i++) {
//             cout << a[i] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
