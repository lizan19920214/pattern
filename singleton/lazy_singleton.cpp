/**
 * 单例模式
 * 作用：
 * 1. 保证一个类只有一个实例。
 * 2. 为该实例提供一个全局访问节点。
 * 实现：
 * 1、 将默认构造函数设为私有， 防止其他对象使用单例类的new运算符。
 * 2、 新建一个静态构建方法作为构造函数。该函数会“偷偷”调用私有构造函数来创建对象，并将其保存在一个静态成员变量中。
 *     此后所有对于该函数的调用都将返回这一缓存对象。
 * 
 * 懒汉式单例：
 * 在第一次获取对象的时候才创建，好处是不需要的时候不创建对象，不占用内存
 * 但是每次获取对象的时候都要判断对象是否为空，而且在多线程的时候会创建多个对象，导致内存泄漏，需要加锁
*/
#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Singleton created." << endl;
    }
public:
    ~Singleton()
    {
        cout << "Singleton destroyed." << endl;
    }

    static Singleton* getSingleton()
    {
        //double lock
        if (m_instance == NULL)
        {
            //lock
            m_mutex.lock();
            if (m_instance == NULL)
            {
                m_instance = new Singleton();
            }
            //unlock
            m_mutex.unlock();
        }

        return m_instance;
    }
    
private:
    static Singleton* m_instance;
    static std::mutex m_mutex;
};

Singleton* Singleton::m_instance = NULL;
std::mutex Singleton::m_mutex;

int main()
{
    Singleton* s1 = Singleton::getSingleton();
    Singleton* s2 = Singleton::getSingleton();
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    return 0;
}