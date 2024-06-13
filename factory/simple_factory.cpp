/**
 * 简单工厂
 * g++ -o simple_factory simple_factory.cpp
 * 简单工厂不符合开闭原则，新增产品需要修改工厂类
*/
#include <iostream>
#include <string>
using namespace std;
class Fruit
{
public:
    ~Fruit(){};
    virtual void sayName() = 0;
};

class Banana : public Fruit
{
public:
    virtual void sayName() override
    {
        cout << "Banana" << endl;
    }
};

class Apple : public Fruit
{
public:
    virtual void sayName() override
    {
        cout << "Apple" << endl;
    }
};

class Factory
{
private:
public:
    ~Factory(){};
    Fruit* create(string name)
    {
        if (name == "Banana")
        {
            return new Banana();
        }
        else if (name == "Apple")
        {
            return new Apple();
        }
        
        return nullptr;
    }
};

int main()
{
    Factory* factory = new Factory();
    Fruit* banana = factory->create("Banana");
    banana->sayName();

    Fruit* apple = factory->create("Apple");
    apple->sayName();

    delete banana;
    delete apple;
    delete factory;

    return 0;
}
