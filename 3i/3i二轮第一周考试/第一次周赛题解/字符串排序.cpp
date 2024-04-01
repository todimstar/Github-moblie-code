#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    string s[101];
    while(cin>>m)
    {
        int num[m];
        for(int i=0;i<m;i++)
        {
            cin>>s[i];
            string str = s[i].substr(s[i].size() - 6, s[i].size() - 1);
            num[i]=stoi(str);
        }
        sort(num,num+m);
        for(int i=0;i<m;i++)
            cout<<num[i]<<endl;
    }
    return 0;
}
