/*如果重复的数<=单独的数，就可以改位置，不然-1*/
#include<iostream>	//算法注释：字符串	，心得：	，题目网址：https://ac.nowcoder.com/acm/contest/92662/E
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int N =1e5+10;
int m[26];


int main (){

	string str;
	cin>>str;
    
	for(int i=0;i<str.length();i++){
        m[str[i]-'a']++;
    }
    vector<int> re,du;
    int recnt=0,ducnt=0;
    for(int i=0;i<26;i++){//统计重复和单独
        if(m[i]>=2){
            re.push_back(i);//记下重复的字母编号
            recnt+=m[i];
        }
        else if(m[i]==1){
            du.push_back(i);//记下单独的字母编号
            ducnt++;
        }
    }
    if(recnt>ducnt)cout<<"-1";
    else{cout<<"re ";
        for(auto i:re)cout<<i<<" ";
         cout<<"\ndu";
         for(auto i:du)cout<<i<<" ";
        char a[str.length()];
        int k=0;
        for(int i=0;i<str.length();i++){//造新字符串
            if(find(re.begin(),re.end(),str[i]-'a') != re.end()){//如果字符串再re里//检查find语法这里报错了
                a[k++]=(char)('a'+du.back());//拿单独的字母编号//检查能否正确强转成对应字母
                du.pop_back();
                cout<<"\n在find里i="<<i<<endl;
            }else{//不在re里则用重复字母填充，重复字母可能不够
                if(re.size()>0){
                    //还有重复字母，用重复字母填充，弹出重复字母
                    //补充
                    
                    if(m[re.back()]-->0){//看此重复字母数量并减减
                        a[k++] = (char)('a' + re.back()); // 用重复字母填充
                        
                    }else{
                        re.pop_back(); // 移除已经使用的重复字母cnt
                    }
                    cout<<"\nre.size()>0里i="<<i<<"k="<<k<<endl;
                }else{
                    //用剩余单独字母填充，弹出
                    //补充
                    a[k++] = (char)('a' + du.back()); // 用单独字母填充
                    du.pop_back(); // 移除已经使用的单独字母
                    cout<<"\nelse里i="<<i<<"k="<<k<<endl;
                }
            }
        }for(int i=0;i<str.length();i++){
            printf("%c ",a[i]);
        }
    }
	
	return 0;
}

/*
#include<iostream>可以通过的，主要是偏移
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

// 自定义结构体C，用于存储字符和其原始位置
struct C {
    char c;  // 字符
    int num; // 原始位置
};

// 自定义排序函数，按照字符的字典序排序
int cmp(const C &a, const C &b) {
    return a.c < b.c;
}

int main() {
    int n[26] = {0}; // 统计每个字母出现的次数
    char s[100005];  // 输入字符串
    cin >> s;
    int len = strlen(s); // 字符串长度
    C c[len]; // 用于存储字符及其原始位置的数组
    
    // 统计每个字符的出现次数，并构造C数组
    for (int i = 0; i < len; i++) {
        n[s[i] - 'a']++;
        c[i].c = s[i];
        c[i].num = i;
    }

    // 找出出现次数最多的字符的次数x，并判断是否有解
    int x = 0;
    for (int i = 0; i < 26; i++) {
        if (n[i] > len / 2) { 
            printf("-1"); 
            return 0; // 如果某个字符数量大于一半，直接输出-1
        }
        if (n[i] > x) x = n[i]; // 更新x为最多的字符数量
    }

    // 对字符数组c按照字符大小排序
    sort(c, c + len, cmp);
    
    // 根据偏移x，将每个字符替换为其后的第x个字符
    for (int i = 0; i < len; i++) {
        s[c[i].num] = c[(i + x) % len].c; // 用偏移后的字符替换原位置
    }

    // 输出结果
    cout << s;
}

*/