/**
 * 抽象工厂模式
 * g++ -o abs_factory abs_factory.cpp
 * 在每一个系列的子系列中符合开闭原则，系列不符合
 * 为所有产品声明抽象产品接口，让所有具体产品类实现这个接口
 * 为所有产品声明抽象工厂接口，让所有具体工厂类实现这个接口
 * 提供一个抽象工厂类，让所有工厂类继承这个抽象工厂类
*/
#include <iostream>
using namespace std;

class Fruit
{
public:
    virtual void sayName() = 0;
};

class LocalApple : public Fruit
{
public:
    virtual void sayName() override
    {
        cout << "LocalApple" << endl;
    }
};

class LocalBanana : public Fruit
{
public:
    virtual void sayName() override
    {
        cout << "LocalBanana" << endl;
    }
};

class ImportApple : public Fruit
{
public:
    virtual void sayName() override
    {
        cout << "ImportApple" << endl;
    }
};

class ImportBanana : public Fruit
{
public:
    virtual void sayName() override
    {
        cout << "ImportBanana" << endl;
    }
};

class Factory
{
public:
    virtual Fruit* createApple() = 0;
    virtual Fruit* createBanana() = 0;
};

class LocalFactory : public Factory
{
public:
    virtual Fruit* createApple() override
    {
        return new LocalApple();
    }
    virtual Fruit* createBanana() override
    {
        return new LocalBanana();
    }
};

class ImportFactory : public Factory
{
public:
    virtual Fruit* createApple() override
    {
        return new ImportApple();
    }
    virtual Fruit* createBanana() override
    {
        return new ImportBanana();
    }
};

int main()
{
    //本地水果
    Factory* localFactory = new LocalFactory();
    Fruit* localApple = localFactory->createApple();
    Fruit* localBanana = localFactory->createBanana();
    localApple->sayName();
    localBanana->sayName();

    //进口水果
    Factory* importFactory = new ImportFactory();
    Fruit* importApple = importFactory->createApple();
    Fruit* importBanana = importFactory->createBanana();
    importApple->sayName();
    importBanana->sayName();

    delete localApple;
    delete localBanana;
    delete importApple;
    delete importBanana;
    delete localFactory;
    delete importFactory;
    return 0;
}
