#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;//  pow(number,pow);

int main (){
	int l,N,i;
    int d,t,all=1;
	cin>>l>>N;
	for(i=1;i<=l;i++)all*=26;
	d=all-N;//+1;因为t%26==0其实是 z
	while(d){
		/*--l;	
		i=pow(26,l);*/
		i=all/26;
		t=d/i;//  当前位置/此位数匹配的26次方阶级数       
		printf("%c",'a'+t%26);
		d=d%i;//把当前位置往下一个26位次挪
		all/=26;// 更新匹配d位的26次方阶级数 
	}
	//printf("\n%d",26*26*26);
	
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,ds;
	cin>>l>>ds;
	int total=1,zs;
	char c[6];
	for(int i=0;i<l;i++)//计算所有可能
		total*=26;
	zs=total-ds+1;//计算正数位置
	if(zs!=total)//如果是最后一个则每一位都赋值为'z'
	{
		total=total/26;
		for(int i=0;i<l;i++)
		{
			if(i==l-1)//最后一位不用再处理，直接可以获取
				c[i]=(char)('a'+zs-1);
			else
			{
				c[i]=(char)('a'+zs/total);//依次找出每一位
				zs%=total;
				total/=26;
			}
		}
	}
	else
		for(int i=0;i<l;i++)
			c[i]='z';
	for(int i=0;i<l;i++)
		cout<<c[i];
}
*/
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,ds;
    char c[6];
	cin>>l>>ds;
	long long sum=pow(26,l)-ds;
    for(int i=l-1;i>=0;i--)
    {
        c[i]='a'+sum%26;
        sum/=26;
    }
	for(int i=0;i<l;i++)
		cout<<c[i];
    return 0;
}*/
/*为什么使用long long sum = pow(26, l) - ds + 1;就会有错位，
long long sum = pow(26, l) - ds ;就没错位，
是因为sum % 26要是等于0其实就是a等于25就是z所以整体往前缩了一位吗

是的，您的理解是正确的。使用 long long sum = pow(26, l) - ds + 1; 会导致结果错位一位，这是因为我们在计算每个字符的索引时，如果 sum % 26 的结果为0，我们实际上需要得到的是字母 'z'，而不是 'a'。
让我们更详细地解释这一点。假设 l 是 3，ds 是 27，那么序列中的倒数第27个字符串应该是 'zzb'。如果我们使用 sum = pow(26, l) - ds + 1，计算得到的 sum 会是 1562（26^3 - 27 + 1）。
现在，我们从这个数开始，从最高位到最低位计算每个字符：*/
//文心听讲后修改   啥本。还是不对，但是我上面理解应该没错 
/*#include<bits/stdc++.h>  
using namespace std;  
int main()  
{  
    int l, ds;  
    char c[6];  
    cin >> l >> ds;  
    long long sum = pow(26, l) - ds + 1; // 注意这里的 +1  
    for (int i = l - 1; i >= 0; i--)  
    {  
        c[i] = (sum % 26 == 0) ? 'z' : 'a' + (sum % 26) - 1; // 如果取模为0，选择'z'，否则选择相应的字符  
        sum /= 26;  
    }  
    for (int i = 0; i < l; i++)  
        cout << c[i];  
    return 0;  
} */

	
	
