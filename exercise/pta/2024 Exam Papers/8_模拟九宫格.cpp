#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int Map[10][10];

bool check9(int ii,int jj){
    map<int,int> nums;
    for(int i=ii;i<ii+3;i++){
        for(int j=jj;j<jj+3;j++){
            nums[Map[i][j]]++;
        }
    }int cnt=0;
    for(int i=1;i<=9;i++){
        if(nums[i])cnt++;
    }
    return cnt==9;
}

bool check(){
    bool flag=true;
    for(int i=0;i<9&&flag;i++){
        map<int,int> nums1,nums2;
        for(int j=0;j<9;j++){
            nums1[Map[i][j]]++;
            nums2[Map[j][i]]++;
        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=9;i++){
            if(nums1[i])cnt1++;
            if(nums2[i])cnt2++;
        }
        flag = (cnt1==9 && cnt2==9);
    }
    return flag;
}


int main(){
	int n;
	cin >> n;
    
	while(n--){
        bool flag=true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>Map[i][j];
            }
        }
        for(int i=0;i<7&&flag;i+=3){
            for(int j=0;j<7;j+=3){
                if(!check9(i,j)){
                    flag=false;
                    break;
                }
            }
        }
        //cout<<flag<<" "<<check()<<endl;
        if(flag && check()){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }


	return 0;
}