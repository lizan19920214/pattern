/**
 * g++ -o observer observer.cpp
 * 观察者模式
 * 定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新
 * 比较常用的比如事件的注册与触发
*/
#include <iostream>
#include <vector>
using namespace std;

//观察者基类
class AbstractObserver
{
public:
    virtual void response() = 0;
};


//发布者
class Publisher
{
public:
    Publisher()
    {
        m_vecObserver.clear();
    }

    ~Publisher()
    {
        for(auto pObserver : m_vecObserver)
        {
            if (pObserver != nullptr)
            {
                delete pObserver;
                pObserver = nullptr;
            }
        }
        m_vecObserver.clear();
    }

    //注册观察者
    void RegisterObserver(AbstractObserver* pObserver)
    {
        m_vecObserver.push_back(pObserver);
    }

    //注销观察者
    void DeleteObserver(AbstractObserver* pObserver)
    {
        for(auto it = m_vecObserver.begin(); it != m_vecObserver.end(); it++)
        {
            if (*it == pObserver)
            {
                m_vecObserver.erase(it);
                break;
            }
        }
    }

    //通知观察者
    void NotifyObserver()
    {
        for(auto pObserver : m_vecObserver)
        {
            pObserver->response();
        }
    }

private:
    std::vector<AbstractObserver*> m_vecObserver;
};

//具体观察者1 老鼠
class Mouse : public AbstractObserver
{
public:
    virtual void response() override
    {
        cout << "Mouse run" << endl;
    }
};

//具体观察者2 狗
class Dog : public AbstractObserver
{
public:
    virtual void response() override
    {
        cout << "dog catch up" << endl;
    }
};


int main()
{
    //发布者实例
    Publisher* publish = new Publisher();
    
    //观察者实例
    Mouse* mouse = new Mouse();
    Dog* dog = new Dog();
    
    //注册观察者
    publish->RegisterObserver(mouse);
    publish->RegisterObserver(dog);

    //发布消息
    publish->NotifyObserver();
    
    
    //释放资源
    delete publish;
    delete mouse;
    delete dog;
    
    publish = nullptr;
    mouse = nullptr;
    dog = nullptr;

    return 0;
}