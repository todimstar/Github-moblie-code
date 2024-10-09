#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> vec1 = {1,1,2,3,3,4,4,5};
	vector<int> vec2 = {1,1,2,3,3,4,4,5};
	auto pos1 = unique(vec1.begin(), vec1.end());	// pos1：指向不重复序列末尾的迭代器。（“末尾”指最后一个元素后一个位置）
    auto pos2 = unique(vec2.begin(), vec2.end()) - vec2.begin();	// pos2：不重复序列的长度。
	//vec1 = vec2 = {1,2,3,4,5,4,4,5};

	// 打印输出使用了unique函数后的vec
    for(int i : vec1) cout << i << ' ';
	cout<<endl;
	cout<<*pos1<<' '<<pos2<<endl;
    return 0;
}