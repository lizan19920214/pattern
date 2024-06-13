/***
 * 原型模式：让对象拥有自我复制的功能
 * 注意深拷贝和浅拷贝
 */
#include <iostream>
#include <string.h>
using namespace std;

class Programmer
{
public:
    ~Programmer() {};
    virtual Programmer* clone() = 0;
    virtual void print() = 0;
};

class CProgrammer : public Programmer
{
public:
    CProgrammer()
    {
        m_name = "";
        m_age = 0;
        m_des = NULL;
    }

    CProgrammer(string name, int age, char* des)
    {
        m_name = name;
        m_age = age;
        m_des = new char[strlen(des) + 1];
        strcpy(m_des, des);
    }
    ~CProgrammer()
    {
        if (m_des != NULL)
        {
            delete[] m_des;
            m_des = NULL;
        }
    }

    virtual Programmer* clone() override
    {
        CProgrammer* tmp = new CProgrammer();
        tmp->m_name = m_name;
        tmp->m_age = m_age;
        //深拷贝
        tmp->m_des = new char[strlen(m_des) + 1];
        strcpy(tmp->m_des, m_des);
        return tmp;
    }

    virtual void print() override
    {
        cout << "name: " << m_name << endl;
        cout << "age: " << m_age << endl;
        cout << "des: " << m_des << endl;
    }
    
private:
    string m_name;
    int m_age;
    char* m_des;
};


int main()
{
    Programmer* p = new CProgrammer("jun", 26, "C Programmer");
    p->print();

    Programmer* p2 = p->clone();
    p2->print();

    delete p;
    delete p2;

    return 0;
}