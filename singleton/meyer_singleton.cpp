/**
 * meyer singleton是Scott Meyers提出的C++单例的推荐写法。它将单例对象作为局部static对象定义在函数内部
 * 它利用了C++编译器的一个特性：如果一个局部static对象在程序中从未被使用过，那么编译器将不会生成该对象的代码。
 * 如果已被使用，则不会再次创建该对象，直接调用该对象。
 * 因此，在程序中，该单例对象只被创建一次，并且只会被创建一次。
 * 该写法在多线程环境下也是安全的。
 * 优点：
 * 解决了普通单例模式全局变量初始化依赖
 * （C++只能保证在同一个文件中声明的static遍历初始化顺序和其遍历声明的顺序一致，但是不能保证不同文件中static遍历的初始化顺序）
 * 缺点：
 * ● 需要C11支持（C11保证static成员初始化的线程安全）
   ● 性能问题（同懒汉模式一样，每次调用GetInstance()方法时需要判断局部static变量是否已经初始化，如果没有初始化就会进行初始化，这个判断逻辑会消耗一点性能）
*/
#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton(){};
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
};

int main()
{
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    if (&s1 == &s2)
    {
        cout << "s1 and s2 are the same instance" << endl;
    }
    else
    {
        cout << "s1 and s2 are not the same instance" << endl;
    }

    return 0;
}
