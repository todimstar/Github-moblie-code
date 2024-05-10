/*class CTString
{←
	char *m_ pData;→//.用于保存字符数据< .
	int....m_ nLen; →//.记录字符长度一
public:←
//.构造函数和析构函数←
	CTString();←
	CTString(char *);←
	CTString(const CTString&);-
	~CTString();←
//.其它成员函数←
	CTString .*Copy( CTString*); >→//.拷贝←
	CTString .*Connect( CTString*);→ →//.连接<
	char*... . Find( CTString*);>→//. 查找子串
	char*... . Find(char);→ →> →//.查找字符←
	void.. Print(); →→//.打印输出字符串内容
*/
#include<iostream>
#include<string.h>
using namespace std;

class CTString
{

	char *m_pData;//用于保存字符数据
	int m_nLen; //记录字符长度
public:
//.构造函数和析构函数
	CTString(){
		m_pData=NULL;
		m_nLen=0;
	}
	CTString(char * str){
		if(str!=NULL){
			m_nLen=strlen(str);//拿到需要分配空间的大小
			m_pData=new char[m_nLen+1];
			if(m_pData){
				strcpy(m_pData,str);//复制内容 
			}else{
				printf("分配m_pData失败\n");
				//throw std::bad_alloc;
			}
		}else{
			m_nLen=0;
			m_nLen=0;
		}
	}
	CTString(const CTString& str){
		m_nLen=str.m_nLen;
		m_pData=new char[m_nLen+1];
		if(m_pData){
			strcpy(m_pData,str.m_pData);
		}else{
			printf("分配m_pData失败\n");
			//throw std::bad_alloc;
		}
	}
	~CTString(){
		delete[] m_pData;//释放
		m_pData=NULL;
		m_nLen=0; 
	}
//.其它成员函数
	CTString *Copy( CTString* orther){ 	//.拷贝←
		orther->
	}
	CTString *Connect( CTString*);	//.连接<
	char* Find( CTString*);	//. 查找子串
	char* Find(char);			//.查找字符←
	void Print(); 				//.打印输出字符串内容
};
