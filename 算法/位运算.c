#include<stdio.h> 
#include<stdlib.h>
int Add(int num1, int num2 ) {
	int cot=0;
    while(num2 != 0) {//进位不为0则持续与相加结果进行相加
        int tmp = num1 ^ num2;//得到每位相加不考虑进位的数据
        ++cot;
		char stmp[33],snum2[33],snum[33];
        itoa(tmp,stmp,2);itoa(num1&num2,snum,2);
		printf("cot=%d,num1^num2=%s,num1&num2=%s",cot,stmp,snum);
        num2 = (num1 & num2) << 1;//同1的位相加则会进位
        itoa(num2,snum2,2);
		printf(",(num1&num2)<<1=%s",snum2);
        num1 = tmp;printf("\n");
    } 
    return num1;
}
int main (){
	int a=15,b=7;
	while(scanf("%d %d",&a,&b)!=EOF){
		char sa[33],sb[33],sab[33];
		itoa(a,sa,2);itoa(b,sb,2);itoa(a^b,sab,2);
		printf("b^a=%d a=%s b=%s b^a=%s\n",b^a,sa,sb,sab);
		printf("%d+%d(Add)=%d",a,b,Add(a,b));
	}
		
	
	
	return 0;
}




//=========首先0^0,0&0,0|0,~0,都等于0，即0做(除取反~以外)位运算等于0本身;
//========按位与(&)，同为1,异为0;
//=======按位或(|)，0|1=1,0|0=0,1|0=1,1|1=1;类似||;
//======按位异或(^)，同为0，异为1;
//====取反对所有整数取反=本身的相反数减一
//====  ~n=(-n)-1;
// ~9 = -10
// ~10 = -11 
