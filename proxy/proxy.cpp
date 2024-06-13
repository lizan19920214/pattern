/**
 * g++ -o proxy proxy.cpp
 * 代理模式
 * 代理的目的是一般是为了防止直接访问某一个类，提供一种类似授权的机制。
 * 最典型的类中set和get方法实际上就是一种代理。
 * 一般形式为：一个抽象接口类，一个真实的需要被代理的实体类，一个代理类，后两个类都继承于抽象接口类
 * 代理类里面管理真实的实体类，通过代理类来操作实体类
*/
#include <iostream>
using namespace std;

//公共接口（抽象类） 代理和真实服务器共同继承
class AbsCommonInterface
{
public:
    virtual void run() = 0;
};

//真实服务器
class MySystem : public AbsCommonInterface
{
public:
    virtual void run()
    {
        cout << "run my system" << endl;
    }
};

//代理类去控制对真实系统的访问
class MyProxy : public AbsCommonInterface
{
public:
    MyProxy(string name, string password)
    {
        m_name = name;
        m_password = password;
        m_system = new MySystem();
    }

    bool checkUser()
    {
        if (m_name == "admin" && m_password == "123456")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    virtual void run() override
    {
        if (checkUser())
        {
            m_system->run();
        }
        else
        {
            cout << "no permission" << endl;
        }
    }

    ~MyProxy()
    {
        if (m_system != nullptr)
        {
            delete m_system;
            m_system = nullptr;
        }
        
    }

private:
    MySystem* m_system;
    string m_name;
    string m_password;
};


int main()
{
    MyProxy* proxy = new MyProxy("admin", "123456");
    proxy->run();
    delete proxy;
    proxy = nullptr;
    return 0;
}