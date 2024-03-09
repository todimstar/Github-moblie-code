#include<iostream>
#include<string.h>
using namespace std;

int main (){
	int len,i,sum=0;
	char str[10002];
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++){
		if((str[i]-'0')%2!=0)sum++;
	}cout<<sum;
	return 0;
}
