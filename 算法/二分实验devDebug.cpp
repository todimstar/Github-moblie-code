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
	// ������������x�ܲ鵽�Ķ���
	while (l <= r) { // l=rҲ�ܲ鵽
		midx = l + (r - l) / 2; //  ����r+l���int��Χ
		if (a[midx] == x) {
			while (midx - 1 >= 0 && a[midx - 1] == x)midx--;
			/*if(midx-1>=0&&a[midx-1]==x){// ��Խ�½�
			    while(midx-1>=0&&a[--midx]==x);
			}*/
			xx = true;
			break;
		} else if (a[midx] > x)r = midx - 1;
		else if (a[midx] < x)l = midx + 1; //+1-1��Ϊ���������Ѳ��mid
	}
	if (a[midx] > x)xx = true;
	l = 0;
	r = n - 1;
	while (l <= r) {
		midy = l + (r - l) / 2;
		if (a[midy] == y) {
			if (midy + 1 <= n - 1 && a[midy + 1] == y) { // ��Խ�Ͻ�
				//while(midy+1<=n-1&&a[midy+1]==y)midy++;//  ��Ų����ִ��һ��
				while (a[++midy] == y) { //��[++num]�������������һ�Σ������һ������������ʱ�����Ҳ��ִ��һ�����Ե���ƫ��+1;
					if (midy + 1 > n - 1)break; //  ����������devcpp�Ҫ������Բ鿴��[++num]�����ôÿִ��һ�����numҲ�������ڵ������ﱻ++��һ��
				}//  ����Ц���ǣ���Ҫ�Ƕ�鿴n��++num����䣬���num����һ�α�͵͵+n; ����devcpp��Ƶ��Եײ�ʱӦ����ֱ��ִ��һ���û��ڵ��Բ鿴�������Ȼ�����������û���ǵ������������Դ���룬����ִ����ĳЩ��Ա����иı�ĵ��ԣ��û�Դ�����еı���Ҳ���ű���

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
	cout<<aa;*/// ��֤mid=left+(right-left)/2�Ľ��
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
	// ��� system("pause") �ķ���������ȴ��û�����
	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
