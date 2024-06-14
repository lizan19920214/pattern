/**
 * g++ -o facade facade.cpp
 * 外观模式:将子系统中的一组接口提供一个一致的界面
 * 外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用
 * 外观可能成为与程序中所有类都耦合的上帝对象。
*/
#include <iostream>
using namespace std;

class SubsysA
{
public:
    void dothingA()
    {
        cout << "SubsysA dothingA" << endl;
    }
};

class SubsysB
{
public:
    void dothingB()
    {
        cout << "SubsysB dothingB" << endl;
    }
};

class SubsysC
{
public:
    void dothingC()
    {
        cout << "SubsysC dothingC" << endl;
    }
};

class Facade
{
public:
    Facade()
    {
        m_sysA = new SubsysA();
        m_sysB = new SubsysB();
        m_sysC = new SubsysC();
    }
    ~Facade()
    {
        if (m_sysA != nullptr)
        {
            delete m_sysA;
            m_sysA = nullptr;
        }
        if (m_sysB != nullptr)
        {
            delete m_sysB;
            m_sysB = nullptr;
        }
        if (m_sysC != nullptr)
        {
            delete m_sysC;
            m_sysC = nullptr;
        }
    }

    void dothing()
    {
        m_sysA->dothingA();
        m_sysB->dothingB();
        m_sysC->dothingC();
    }

private:
    SubsysA* m_sysA;
    SubsysB* m_sysB;
    SubsysC* m_sysC;
};

int main()
{
    //使用外观模式之前
    SubsysA* a = new SubsysA();
    SubsysB* b = new SubsysB();
    SubsysC* c = new SubsysC();
    a->dothingA();
    b->dothingB();
    c->dothingC();
    delete a;
    delete b;
    delete c;

    //使用外观模式
    Facade* f = new Facade();
    f->dothing();
    delete f;

    return 0;
}


