#include <iostream>  //========ai.cpp  以下全寄,ai答案错误，ai.c:1 2^32-1 ai.cpp:(2^32/2),my.c及.cpp==timelit last 
#include <vector>  
#include <algorithm>  
  
int main() {  
    int N;  
    std::cin >> N;  
  
    std::vector<std::pair<long long, long long>> records(N);  
    for (int i = 0; i < N; i++) {  
        std::cin >> records[i].first >> records[i].second;  
    }  
  
    // 计算最大可能值Vmax  
    long long Vmax = 0;  
    for (const auto& record : records) {  
        Vmax = std::max(Vmax, (record.first + record.second - 1) / record.second);  
    }  
  
    // 使用二分搜索找到最小可能值Vmin  
    long long Vmin = 1, VmaxTest = Vmax;  
    while (Vmin < VmaxTest) {  
        long long Vmid = Vmin + (VmaxTest - Vmin) / 2;  
        bool valid = true;  
        for (const auto& record : records) {  
            if (record.first < Vmid || record.first % Vmid != 0 || record.first / Vmid < record.second) {  
                valid = false;  
                break;  
            }  
        }  
        if (valid) {  
            VmaxTest = Vmid;  
        } else {  
            Vmin = Vmid + 1;  
        }  
    }  
  
    std::cout << Vmin << " " << Vmax << std::endl;  
    return 0;  
}

/*#include <stdio.h>  //==============ai.c
#include <stdlib.h>  
#include <limits.h>  
  
int N;  
int oxa[10001], oxb[10001];  
  
int check(int v) {  
    for (int i = 0; i < N; i++) {  
        if (oxa[i] < v) return 0; // Not enough metal to produce even one X  
        if (oxa[i] % v != 0) return 0; // Cannot produce exactly oxb[i] Xes  
        if (oxb[i] * v > oxa[i]) return 0; // Not enough metal to produce oxb[i] Xes  
    }  
    return 1; // All conditions satisfied  
}  
  
int main(int argc, char *argv[]) {  
    scanf("%d", &N);  
    for (int i = 0; i < N; i++) {  
        scanf("%d %d", &oxa[i], &oxb[i]);  
    }  
  
    int l = 1, r = INT_MAX; // Search range for V  
    while (l < r) {  
        int mid = l + (r - l) / 2;  
        if (check(mid)) {  
            r = mid; // V can be at most mid  
        } else {  
            l = mid + 1; // V must be greater than mid  
        }  
    }  
  
    int vmax = l; // V cannot be greater than l  
  
    l = 1, r = vmax; // Reset search range for finding vmin  
    while (l < r) {  
        int mid = l + (r - l + 1) / 2;  
        if (check(mid)) {  
            l = mid; // V can be at least mid  
        } else {  
            r = mid - 1; // V must be less than mid  
        }  
    }  
  
    int vmin = l; // V cannot be less than l  
  
    printf("%d %d\n", vmin, vmax);  
    return 0;  
}*/
/*#include <stdio.h>//==================my.c
#include <stdlib.h>

int N,vmin,vmax;

int oxa[10001],oxb[10001];
int zhuanhuan(int v);

void change(int mid){
  int orign=mid,flag=1;
  while(flag){
    if(!zhuanhuan(mid++)){vmax=mid-2;flag=0;}
  }flag=1;
  while(flag){
    if(!zhuanhuan(orign--)){vmin=orign+2;flag=0;}
  }
}

int zhuanhuan(int v){
  int flag=0,jg;
  for(int i=0;i<N;i++){jg=oxa[i]/v;
      if(jg==oxb[i])flag++;
      else if(jg<oxb[i])return 1;//v大
      else if(jg>oxb[i])return -1;//v小
  }if(flag==N)return 2;
  else return 0;
}

int half(int l,int r){
  int mid=(l+r+1)/2;
  int flag=zhuanhuan(mid);
  
  if(flag==1){r=mid-1;half(l,r);}
  if(flag==-1){l=mid+1;half(l,r);}
  if(flag==2){change(mid);return 1;}
  
  return 0;
}

int main(int argc, char *argv[])
{
  scanf("%d",&N);
  for(int i=0;i<N;i++)scanf("%d %d",&oxa[i],&oxb[i]);
  if(half(1,1e9)){
    printf("%d %d",vmin,vmax);
  }
  else printf("what up?");
  return 0;
}*/

/*#include <iostream>//=====================mycpp;
#include<vector>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

int N,vmin,vmax;

int oxa[N],oxb[N];
int zhuanhuan(int v);

void change(int mid){
  int orign=mid,flag=1;
  while(flag){
    if(!zhuanhuan(mid++)){vmax=mid-2;flag=0;}
  }flag=1;
  while(flag){
    if(!zhuanhuan(orign--)){vmin=orign+2;flag=0;}
  }
}

int zhuanhuan(int v){
  int flag=0;
  for(int i=0;i<N;i++){
      if((oxa[i]/v)==oxb[i])flag++;
      else if((oxa[i]/v)<oxb[i])return 1;//v大
      else if((oxa[i]/v)>oxb[i])return -1;//v小
  }if(flag==N)return 2;
  else return 0;
}

int half(int l,int r){
  int mid=(l+r+1)/2;
  int flag=zhuanhuan(mid);
  
  if(flag==1)r=mid-1;
  if(flag==-1)l=mid+1;
  if(flag==2){change(mid);return 1;}
  half(l,r);
  return 0;
}

int main(int argc, char *argv[])
{
  scanf("%d",&N);
  for(int i=0;i<N;i++)scanf("%d %d",&oxa[i],&oxb[i]);
  if(half(1,1e9)){
    printf("%d %d",vmin,vmax);
  }

  return 0;
}*/
