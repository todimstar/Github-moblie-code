#include<iostream>

using namespace std;

class cft{
	
	public:
		//函数设置长宽高 
		void setL(int l){m_L=l;}
		void setW(int w){m_W=w;}
		void setH(int h){m_H=h;}
		void setLWH(int l,int w,int h){
			m_L=l;
			m_H=h;
			m_W=w;
		}
		
		int getL(){return m_L;}
		int getW(){return m_W;}
		int getH(){return m_H;}
		
		bool comparecft_class(cft b){
			if(b.getH()==m_H&&b.getW()==m_W&&b.getL()==m_L)return true;
			return false;
		}
	
	private:
		int m_L;
		int m_W;
		int m_H;
};

bool comparecft(cft a,cft b){
	if(b.getH()==a.getH()&&b.getW()==a.getW()&&b.getL()==a.getL())return true;
	return false;
}

int main (){
	cft c1,c2;
	
	c1.setLWH(10,10,10);
	c2.setLWH(10,10,10);
	
	bool shuijiao=c1.comparecft_class(c2);
	bool ret=comparecft(c1,c2);
	
	cout<<shuijiao<<" and "<<ret<<endl;
	
	return 0;
}
