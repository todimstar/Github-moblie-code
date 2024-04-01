#include<stdio.h>//===输入两个200位的数，求和======== 
#include<string.h>
int main (){//=======高精度加法==== 
	char s1[205]={0},s2[205]={0};
	int a[250]={0},b[250]={0},c[250]={0};
	int i,len1,len2,lenmax;
	
	scanf("%s",s1);
	scanf("%s",s2);
	len1=strlen(s1);
	len2=strlen(s2);
	for(i=0;i<len1;i++){
		a[i]=s1[len1-1-i]-'0';
	}
	for(i=0;i<len2;i++){
		b[i]=s2[len2-1-i]-'0';
	}
	lenmax=len1>len2?len1:len2;//===以大的数为准=== 
	for(i=0;i<lenmax;i++){
		c[i]+=a[i]+b[i];//===保留进位=== 
		if(c[i]>=10){//====处理进位; 
			c[i+1]+=1;
			c[i]%=10;
		}
	}
	if(c[lenmax]!=0){
		printf("%d",c[lenmax]);
	}
	for(i=lenmax-1;i>-1;i--){
		printf("%d",c[i]);
	}
	
	return 0;
}
