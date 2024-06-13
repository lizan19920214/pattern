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
 * 饿汉式单例：
 * 默认就会创建一个静态对象，在获取示例时直接返回该对象即可，缺点就是即使不用也会占用内存，而且线程安全
*/

#include <iostream>
#include <string>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Singleton create" << endl;
    }
public:
    ~Singleton()
    {
        cout << "Singleton destory" << endl;
    }

    static Singleton* getInstance()
    {
        return m_instance;
    }

private:
    static Singleton* m_instance;
};

Singleton* Singleton::m_instance = new Singleton();

int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if (s1 == s2)
    {
        cout << "s1 and s2 are the same instance" << endl;
    }
    else
    {
        cout << "s1 and s2 are not the same instance" << endl;
    }

    return 0;
}