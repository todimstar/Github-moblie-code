#include<stdio.h>
#include<string.h>

int main (){
    int n,i,lena,lenb,len,c[1000]={0},s1[250]={0},s2[250]={0};
    char a[250],b[250];
    scanf("%d",&n);
    while(n--){
        scanf("%s %s",a,b);//==========字符串输入 
        lena=strlen(a);lenb=strlen(b);
        len=lena>lenb?lena:lenb;
        for(i=0;i<lena;i++){//============两循环入int数组 
				s1[i]=a[lena-1-i]-'0';
			}
		for(i=0;i<lenb;i++){
			s2[i]=b[lenb-1-i]-'0';
		}
        for(i=0;i<len;i++){
            c[i]+=s1[i]+s2[i];//===========逐个加 
            if(c[i]>9){
                c[i+1]+=1;
                c[i]%=10;
                
            }
        }if(c[len]!=0){
            printf("%d",c[len]);
        }
        for(i=len-1;i>=0;i--){
            printf("%d",c[i]);c[i]=0;
        }printf("\n");
        
    }
    
    return 0;
}
