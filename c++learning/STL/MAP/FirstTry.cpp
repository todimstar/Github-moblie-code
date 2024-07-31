#include<iostream>
#include<map>
using namespace std;

void printMap(map<int,int>&m){
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<"key="<<(*it).first<<" value="<<it->second<<endl;
    }cout<<endl;
    
}


void test01(){
    //map特性：
    //1. map中元素都是pair (键值对);
    //2. first为 key (键值)，second为 value (实值);
    //3. map中会按照 key 自动排序
    //底层是二叉树
    //map不会有重复 key , multimap 可以有，但是目前不知道有啥用

    //创建map容器  
    map<int,int>m;

    m.insert(pair<int,int>(5,1));
    m.insert(pair<int,int>(9,1));
    m.insert(pair<int,int>(1,1));
    m.insert(pair<int,int>(3,1));

    m.insert(pair<int,int>(5,1));
    m.insert(pair<int,int>(9,1));
    m.insert(pair<int,int>(1,1));
    m.insert(pair<int,int>(3,1));

    printMap(m);

    //拷贝构造
    map<int,int> m2(m);
    printMap(m2);

    //赋值
    map<int,int>m3;
    m3=m2;
    printMap(m3);

}

void test02(){
    /*map容器大小操作和交换操作
            size()      swap()
            empty()*/

   //大小操作
    map<int,int>m;
    m.insert(pair<int,int>(1,11));
    m.insert(pair<int,int>(2,22));
    m.insert(pair<int,int>(3,33));

    if(m.empty())
    {
        cout<<"空的m"<<endl;
    }    else {
        cout<<"没空"<<endl;
        cout<<"m大小为"<<m.size()<<endl;
    }

    //交换操作
    map<int,int>m1;
    m1.insert(pair<int,int>(5,51));
    m1.insert(pair<int,int>(6,62));
    m1.insert(pair<int,int>(7,73));
    map<int,int>m2;
    m2.insert(pair<int,int>(8,81));
    m2.insert(pair<int,int>(9,92));
    m2.insert(pair<int,int>(10,03));

    cout<<"m1m2交换前："<<endl<<"m1:";

    printMap(m1);cout<<"m2:";
    printMap(m2);

    m1.swap(m2);//swap()直接两个换了
    cout<<"m1m2交换后："<<endl<<"m1:";

    printMap(m1);cout<<"m2:";
    printMap(m2);

}

int main (){
	test02();
	system("pause");
	
	return 0;
}
