#include <iostream>//https://ac.nowcoder.com/acm/contest/93002
using namespace std;

int min_operations(long long x, long long y) {
    int operations = 0;
    if (x != y) {
        // 如果 x | y ==y，则证明只需要将一些0位设置为 1，x的某些位上是0而y那位上是1，且其他1、0都对上位了
        if ((x | y) == y) {
            operations++;
            return operations;
        }
        // 如果 x & y == y，则证明只需要将一些1位设置为 0，x的某些位上是1而y那位上是0，且其他1、0都对上位了
        if ((x & y) == y) {
            operations++;
            return operations;
        }
        // 无法通过一次操作完成，需要分别执行按位或和按位与
        //因为任何x经过一次|和一次&都可以变成y，就算是0110和0001都可以
        if(operations != 2){
            operations += 2;
            return operations;
        }
    }return operations;
    
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long x, y;
        cin >> x >> y;
        int result = min_operations(x, y);
        cout << result << endl;
    }
    return 0;
}



/*#include<iostream>	//算法注释：	，心得：	，题目网址：
#include<stdlib.h>
#include<string>

using namespace std;

const int N =1e5+10;


int check(long long a,long long b){
	int t=0,contb1 = 0,contb0 = 0;
    int conta1=0,conta0=0;

    if(a == 0)conta0 = 1;
    else{
        while(a){
            if(a%2){
                conta1++;
            }else conta0++;
            a=a>>1;
        }
    }
    if(b == 0)contb0 = 1;
    else{
        while(b){
            if(b%2){
                contb1++;
            }else contb0++;
            b=b>>1;
            
        }
    }
    t=0;
    if(conta1 > contb1){//a中1大于b中1，要1 -> 0 用|
        t++;
    }
    if(conta0 > contb0){//a中0大于b中0，要0 ->1 用&
        t++;
    }

    return t;

}


int main (){
	int T;
    long long a,b;
	int numa[100001],numb[100001];
	
    cin>>T;
    while(T--){
        cin>>a>>b;
        
        int jg = check(a,b);

        cout<<jg;
    }
	
	return 0;
}
*/