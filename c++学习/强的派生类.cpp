//1. 派生类的声明格式：
//class 派生类名 : 派生方式 基类名
//{
//    // 派生类新特性（新增成员）
//[private:]
//    私有数据成员和成员函数；
//public:
//    公有数据成员和成员函数；
//};
//2. 派生类的构造函数和析构函数 *
//1）派生类两构函数的执行顺序
//2）派生类两构函数的构造规则
//3. 调整派生类中的访问属性的其他方法
//1）同名成员
//2）访问声明

#include <iostream>
#include <cstring>

class CEmpoyee {
private:
    char* m_pName;  // 姓名
    int m_nAge;     // 年龄
    float m_fSalary;  // 薪水

public:
    // 构造函数和析构函数
    CEmpoyee(const char* pName = nullptr, int age = 0, float salary = 0.0);
    CEmpoyee(const CEmpoyee&);
    ~CEmpoyee();

    // 其它成员函数
    void SetName(char*);
    char* GetName();
    void SetAge(int);
    int GetAge();
    void SetSalary(float);
    float GetSalary();
    void Print();
};
class CManager :public CEmpoyee {
private:
    int m_nLevel;  // 级别

public:
    // 构造函数和析构函数
    CManager(const char* pName = nullptr, int age = 0, float salary = 0.0, int nLevel = 0);
    CManager(const CEmpoyee, int);
    ~CManager()=default;

    // 其它成员函数
    void SetLevel(int);
    int GetLevel();
    void Print(); 
};
// CEmpoyee成员函数实现
CEmpoyee::CEmpoyee(const char* pName, int age, float salary) : m_nAge(age), m_fSalary(salary) {
    if (pName) {
        m_pName = new char[strlen(pName) + 1];
        strcpy(m_pName, pName);
    }
    else {
        m_pName = nullptr;
    }
}

CEmpoyee::CEmpoyee(const CEmpoyee& other) : m_nAge(other.m_nAge), m_fSalary(other.m_fSalary) {
    if (other.m_pName) {
        m_pName = new char[strlen(other.m_pName) + 1];
        strcpy(m_pName, other.m_pName);
    }
    else {
        m_pName = nullptr;
    }
}

CEmpoyee::~CEmpoyee() {
    delete[] m_pName;
}

void CEmpoyee::SetName(char* name) {
    delete[] m_pName;
    if (name) {
        m_pName = new char[strlen(name) + 1];
        strcpy(m_pName, name);
    }
    else {
        m_pName = nullptr;
    }
}

char* CEmpoyee::GetName() {
    return m_pName;
}

void CEmpoyee::SetAge(int age) {
    m_nAge = age;
}

int CEmpoyee::GetAge() {
    return m_nAge;
}

void CEmpoyee::SetSalary(float salary) {
    m_fSalary = salary;
}

float CEmpoyee::GetSalary() {
    return m_fSalary;
}

void CEmpoyee::Print() {
    std::cout << "Name: " << m_pName << ", Age: " << m_nAge << ", Salary: " << m_fSalary << std::endl;
}

//// CManager成员函数实现
//CManager::CManager(char* pName, int age, float salary, int nLevel) : CEmpoyee(pName, age, salary), m_nLevel(nLevel) {}
//
//CManager::CManager(const CEmpoyee& employee, int nLevel) : CEmpoyee(employee), m_nLevel(nLevel) {}
//
//CManager::~CManager() {}

void CManager::SetLevel(int level) {
    m_nLevel = level;
}

int CManager::GetLevel() {
    return m_nLevel;
}

void CManager::Print() {
    std::cout << "Name: " << GetName() << ", Age: " << GetAge() << ", Salary: " << GetSalary() << ", Level: " << m_nLevel << std::endl;
}

int main() {
    // 创建CEmpoyee对象
    CEmpoyee emp("John", 30, 50000);
    emp.Print();

    // 创建CManager对象
    CManager manager("Alice", 35, 70000, 2);
    manager.Print();

    // 测试CManager的不同派生方式
    CManager manager1(emp, 3);  // 使用基类对象进行初始化
    manager1.Print();

    return 0;
}
