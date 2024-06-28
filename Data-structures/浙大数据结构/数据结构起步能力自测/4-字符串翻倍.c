#include<stdio.h>
#include<string.h>

int c[11];
void fan(int len,char a[]);
void jilv(int len,char a[]);
int zhuan(char a){
	return a-'0';
}

int main (){
	char a[21];
	int len;
	scanf("%s",a);
	len=strlen(a);
	jilv(len,a);
	fan(len,a);
	return 0;
}

void jilv(int len,char a[]){
	for(int i=0;i<len;i++){
		c[zhuan(a[i])]++;
	}
}

void fan(int len,char a[]){
	int i,t=0,cot;char b[21]={0};
	for(i=len-1;i>=0;i--){
		t+=zhuan(a[i])*2;
		if(t>9){cot=0;
			while((t-10)>=0){
				cot++;t-=10;
			}
			b[i]=t+'0';
			t=cot;
		}else{
			b[i]=t+'0';
			t=0;
		}
		if(!c[b[i]-'0']){
			c[10]=-1;
			break;
		}else c[b[i]-'0']++;	
	}
	if(c[10]==-1){
		printf("No\n");
		return;
	}
	else{for(int i=0;i<10;i++){
			if(c[i]==1){
				printf("No\n");
				return;
			}
		}
		printf("Yes\n");
		if(t){
			printf("%d",t);
		}
		puts(b);//还是过不了3种问题 
	}
	
} 
