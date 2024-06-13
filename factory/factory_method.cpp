/**
 * 工厂方法模式
 * g++ -o factory_method factory_method.cpp
 * 工厂方法模式符合开闭原则，添加新产品不需要修改原有代码，只要增加新的产品工厂类即可
 * 缺点：每增加一个产品，就需要增加一个产品工厂类
*/
#include <iostream>
using namespace std;

class Fruit
{
public:
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

class Facory
{
public:
    virtual Fruit* createFruit() = 0;
};

class BananaFactory : public Facory
{
public:
    virtual Fruit* createFruit() override
    {
        return new Banana();
    }
};

class AppleFactory : public Facory
{
public:
    virtual Fruit* createFruit() override
    {
        return new Apple();
    }
};

int main()
{
    BananaFactory* b_factory = new BananaFactory();
    Fruit* banana = b_factory->createFruit();
    banana->sayName();

    AppleFactory* a_factory = new AppleFactory();
    Fruit* apple = a_factory->createFruit();
    apple->sayName();

    // 释放内存
    delete banana;
    delete apple;
    delete b_factory;
    delete a_factory;
    return 0;
}
