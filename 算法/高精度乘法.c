/*#include<stdio.h>
#include<string.h>
int main (){//高精度乘法 
	char s1[250];
	int i,len,a[250],c[300]={0};
	scanf("%s",s1);
	len=strlen(s1);
	for(i=0;i<len;i++){
		a[len-1-i]=s1[i]-'0';
	}
	for(i=0;i<len;i++){
		c[i]+=a[i]*2;
		//处理进位
		if(c[i]>=10){
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	}
	while(c[len]>0){
		if(c[len]>=10){
			c[len+1]=c[len]/10;
			c[len]%=10;
		}len++;
	}for(i=len-1;i>=0;i--){
		printf("%d",c[i]);
	}
	return 0;
}*/

//======杰杰学长给大家问好，高精度*高精度;

#include<stdio.h>
#include<string.h>
void gjdcf (char a[],char b[]){//高精度乘法 
    
	int i,j,lenmin,lenmax,lena,lenb,aa[250],bb[250],c[300]={0};
	lena=strlen(a);lenb=strlen(b);
	for(i=0;i<lena;i++){
		aa[lena-1-i]=a[i]-'0';
	}
    for(i=0;i<lenb;i++){
		bb[lena-1-i]=b[i]-'0';//倒转a,b数字
	}lenmax=lena>=lenb?lena:lenb;
	lenmin=lena>=lenb?lenb:lena;
	if(lenmax==lena){
		for(i=0;i<lenb;i++){
			for(j=0;j<lenmax;j++){
				c[i]+=aa[j]*bb[i];//诸位相乘
				//处理进位
				if(c[i]>=10){
					c[i+1]+=c[i]/10;
					c[i]%=10;
				}
			}
		}
	}else{
		for(i=0;i<lena;i++){
			for(j=0;j<lenmax;j++){
				c[i]+=aa[i]*bb[j];//诸位相乘
				//处理进位
				if(c[i]>=10){
					c[i+1]+=c[i]/10;
					c[i]%=10;
				}
			}
		}	
	}
	while(c[lenmin]>0){
		if(c[lenmin]>=10){
			c[lenmin+1]=c[lenmin]/10;
			c[lenmin]%=10;
		}lenmin++;
	}for(i=lenmin-1;i>=0;i--){
		printf("%d",c[i]);
	}printf("\n");
}
int main (){
    int t;
    char a[15],b[15];
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",a,b);
        gjdcf(a,b);
    }//高精度乘法捏
    
    return 0;
} 
