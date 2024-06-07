#include<stdio.h>
#include<string.h>
char b[25];
char zhuan(int c){
	return c+'0';
}
void huan(char a[],int len){
	int tlen,cot=1,lencot=1,i;
	char t;
	b[0]=a[0]; 
	tlen=len-2;
	while(tlen/=10){cot*=10;lencot++;}
	tlen=len-2;
	for(i=1;i<=lencot;i++){
		t=zhuan(tlen/cot);
		b[i]=t;  
		tlen%=cot;cot/=10;
	}b[lencot+1]=a[len-1];
	
}
int main (){
	int len;
	char a[114514];
	scanf("%s",a);
	len=strlen(a);
	if(len>10){
		huan(a,len);
		printf("%s",b);
	}else{
		printf("%s",a);
	}
	
	return 0;
}
