/**
 * g++ -o builder builder.cpp
 * 创建者/生成器模式
 * 对象的创建和对象的表示分离
 * 分步骤创建复杂对象。该模式允许你使用相同的创建　代码生成不同类型和形式的对象
 * 1. 清晰地定义通用步骤， 确保它们可以制造所有形式的产品。否则你将无法进一步实施该模式。
2. 在基本生成器接口中声明这些步骤。
3. 为每个形式的产品创建具体生成器类，并实现其构造步骤。不要忘记实现获取构造结果对象的方法。
你不能在生成器接口中声明该方法，因为不同生成器构造的产品可能没有公共接口，因此你就不知道该方法返回的对象类型。
但是，如果所有产品都位于单一类层次中，你就可以安全地在基本接口中添加获取生成对象的方法。
4. 考虑创建主管类。它可以使用同一生成器对象来封装多种构造产品的方式。
5. 客户端代码会同时创建生成器和主管对象。构造开始前，客户端必须将生成器对象传递给主管对象。通常情况下，
客户端只需调用主管类构造函数一次即可。主管类使用生成器对象完成后续所有制造任务。还有另一种方式，那就是客户端可以将生成器对象直接传递给主管类的制造方法。
6. 只有在所有产品都遵循相同接口的情况下，构造结果可以直接通过主管类获取。否则，客户端应当通过生成器获取构造结果。
*/
#include <iostream>
#include <string>
using namespace std;

class House
{
public:
    void setFloor(string floor)
    {
        m_floor = floor;
    }

    void setWall(string wall)
    {
        m_wall = wall;
    }

    void setDoor(string door)
    {
        m_door = door;
    }
    
    void show()
    {
        cout << "floor: " << m_floor << endl;
        cout << "wall: " << m_wall << endl;
        cout << "door: " << m_door << endl;
    }
private:
    string m_floor;
    string m_wall;
    string m_door;
};

class Builder
{
public:
    virtual void makeFloor() = 0;
    virtual void makeWall() = 0;
    virtual void makeDoor() = 0;

    House* getHouse()
    {
        return m_house;
    }
    
protected:
    House* m_house;
};

class FlatBuild : public Builder
{
public:
    FlatBuild()
    {
        m_house = new House();
    }

    ~FlatBuild()
    {
        if (m_house != nullptr)
        {
            delete m_house;
            m_house = nullptr;
        }
    }

    void makeFloor() override
    {
        m_house->setFloor("flat floor");
    }

    void makeWall() override
    {
        m_house->setWall("flat wall");
    }

    void makeDoor() override
    {
        m_house->setDoor("flat door");
    }
};

class VillaBuilder : public Builder
{
public:
    VillaBuilder()
    {
        m_house = new House();
    }
    
    ~VillaBuilder()
    {
        if (m_house != nullptr)
        {
            delete m_house;
            m_house = nullptr;
        }
    }

    void makeFloor() override
    {
        m_house->setFloor("villa floor");
    }

    void makeWall() override
    {
        m_house->setWall("villa wall");
    }

    void makeDoor() override
    {
        m_house->setDoor("villa door");
    }

};

class Director
{
public:
    void SetBuilder(Builder* builder)
    {
        m_builder = builder;
    }

    House* construct()
    {
        m_builder->makeFloor();
        m_builder->makeWall();
        m_builder->makeDoor();
        return m_builder->getHouse();
    }

private:
    Builder* m_builder;
};

int main()
{
    Director* director = new Director();
    Builder* f_builder = new FlatBuild();
    director->SetBuilder(f_builder);
    House* f_house = director->construct();
    f_house->show();

    Builder* v_builder = new VillaBuilder();
    director->SetBuilder(v_builder);
    House* v_house = director->construct();
    v_house->show();

    delete f_builder;
    delete v_builder;
    delete f_house;
    delete v_house;
    delete director;

    return 0;
}