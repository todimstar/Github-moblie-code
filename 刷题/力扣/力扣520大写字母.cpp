#include<iostream>
#include<stdlib.h>

using namespace std;

//最开始的分类讨论
string word="Leetcode";
bool detectCapitalUse() {
	int len = word.length();
	if (len == 1)return true;
	//cout<<len<<endl;
	if (word[0] < 'a') { //是大写开头
		if(word[1]<='Z'){//第二个也是大写，走一路大写 
			for (int i = 1; i < len; i++) {
				if (word[i] >= 'a')return false;//有小写就寄 
			}
		}else{//是小写，小写到底 
			for (int i = 1; i < len; i++) {
				if (word[i] < 'a')return false;//有大写就寄 
			}
		} 

	} else {
		for (int i = 1; i < len; i++) { //是小写开头
			if (word[i] <= 'Z')return false;
		}
	}
	return true;

}
//题解说的直看cnt
class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0,len=word.size();
        for(int i=0;i<len;i++){
            if(word[i]<'a')cnt++;//大写
        }
        if(cnt==len||cnt==0)return true;
        else if(cnt==1){
            if(word[0]<'a'){return true;}
            return false;
        }return false;
    }
};
//官解的定头和定2，排1小2大，剩下只有要保持跟2一致大小，便都是允许的
    bool detectCapitalUse(string word) {
        // 若第 1 个字母为小写，则需额外判断第 2 个字母是否为小写
        if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
            return false;
        }
        
        // 无论第 1 个字母是否大写，其他字母必须与第 2 个字母的大小写相同
        for (int i = 2; i < word.size(); ++i) {
            if (islower(word[i]) ^ islower(word[1])) {
                return false;
            }
        }
        return true;
    }
//捡到的正则表达式，但不了解原理
regex re("[A-Z]?([a-z]*|[A-Z]*)");
class Solution {
public:
    bool detectCapitalUse(string word) {
        return regex_match(word, re);
    }
};

int main (){
	
	cout<<detectCapitalUse(); 
	return 0;
}










