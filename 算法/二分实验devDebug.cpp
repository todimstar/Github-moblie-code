#include<iostream>
#include<stdlib.h>
using namespace std;

struct xy {
	int x, y;
};

int compare(const void* a, const void* b) {
	return (*(int*)a - * (int*)b);
}

int erfen(const int* a, int n, const int x, const int y) {
	int l = 0, r = n - 1;
	int midx, midy;
	bool xx = false, yy = false;
	// 对于数组中有x能查到的二分
	while (l <= r) { // l=r也能查到
		midx = l + (r - l) / 2; //  避免r+l溢出int范围
		if (a[midx] == x) {
			while (midx - 1 >= 0 && a[midx - 1] == x)midx--;
			/*if(midx-1>=0&&a[midx-1]==x){// 防越下界
			    while(midx-1>=0&&a[--midx]==x);
			}*/
			xx = true;
			break;
		} else if (a[midx] > x)r = midx - 1;
		else if (a[midx] < x)l = midx + 1; //+1-1是为了跳过已搜查的mid
	}
	if (a[midx] > x)xx = true;
	l = 0;
	r = n - 1;
	while (l <= r) {
		midy = l + (r - l) / 2;
		if (a[midy] == y) {
			if (midy + 1 <= n - 1 && a[midy + 1] == y) { // 防越上界
				//while(midy+1<=n-1&&a[midy+1]==y)midy++;//  这才不会多执行一次
				while (a[++midy] == y) { //把[++num]做条件，会多做一次，当最后一次条件不满足时该语句也会执行一次所以导致偏差+1;
					if (midy + 1 > n - 1)break; //  哈哈而且在devcpp里，要是你调试查看了[++num]语句那么每执行一句你的num也会悄悄在调试那里被++了一次
				}//  更搞笑的是，你要是多查看n个++num的语句，你的num还会一次被偷偷+n; 所以devcpp设计调试底层时应该是直接执行一遍用户在调试查看栏的语句然后输出，并且没考虑到隔离调试栏与源代码，导致执行完某些会对变量有改变的调试，用户源代码中的变量也跟着变了

				/*{
					midy++;
				}*/
			}
			yy = true;
			break;
		} else if (a[midy] > y)r = midy - 1;
		else if (a[midy] < y)l = midy + 1;
	}
	if (a[midy] < y)yy = true;

	if (xx && yy) {
		return midy - midx + 1;
	}
	return -1;
}

int main () {
	/*printf("%d\n",3+(1)/2);
	int aa=3+(1)/2;
	cout<<aa;*/// 验证mid=left+(right-left)/2的结果
	int n, i;
	cin >> n;
	int* a = new int[n];
	for (i = 0; i < n; i++)cin >> a[i];
	int q;
	cin >> q;
	xy* feng = new xy[q];
	for (i = 0; i < q; i++) {
		cin >> feng[i].x >> feng[i].y;
	}
	qsort(a, n, sizeof(a[0]), compare);
	for (i = 0; i < q; i++) {
		cout << erfen(a, n, feng[i].x, feng[i].y) << endl;
	}
	delete[] a;
	delete[] feng;
	// 替代 system("pause") 的方法，例如等待用户输入
	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
