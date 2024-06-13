/**
 * g++ -o adapter adapter.cpp
 * 适配器模式
 * 适配器是一种结构型设计模式，它能使接口不兼容的对象能够相互合作。
 * 一个经典的方钉与圆孔问题，我们让方钉适配圆孔，
 * 就需要增加方钉适配器
*/
#include <iostream>
#include <cmath>
using namespace std;

//圆钉
class RoundPeg
{
public:
    virtual int get_radius() = 0;
};

//方钉
class SquarePeg
{
public:
    explicit SquarePeg(int w): width(w) {}

    int get_width()
    { 
        return width;
    }
private:
    int width;
};

//圆孔
class RoundHole
{
public:
    explicit RoundHole(int r) : radius(r) {}

    //判断圆孔是否能放入圆钉
    bool isFit(RoundPeg* rp)
    {
        return radius >= rp->get_radius();
    }

private:
    int radius;
};

//方钉转圆钉适配器
class SquarePegAdapter : public RoundPeg
{
public:
    explicit SquarePegAdapter(SquarePeg* sp) : sp(sp) {}

    int get_radius() override
    {
        return sp->get_width() * sqrt(2) / 2;
    }
private:
    SquarePeg* sp;
};


int main()
{
    //创建一个半径为10的圆孔
    RoundHole* hole = new RoundHole(10);

    //创建半径为5和20的方钉
    SquarePeg* s_sp = new SquarePeg(5);
    SquarePeg* b_sp = new SquarePeg(20);
    //创建对应的转换器
    SquarePegAdapter* s_sp_adapter = new SquarePegAdapter(s_sp);
    SquarePegAdapter* b_sp_adapter = new SquarePegAdapter(b_sp);

    //直接将方钉放入圆孔会报错
    // hole->isFit(s_sp);
    // hole->isFit(b_sp);

    //使用适配器将方钉转换为圆钉后，放入圆孔不会报错
    bool s_state = hole->isFit(s_sp_adapter);
    if (s_state)
    {
        cout << "width 5 square peg fit round hole" << endl;
    }
    else
    {
        cout << "width 5 square peg not fit round hole" << endl;
    }

    bool b_state = hole->isFit(b_sp_adapter);
    if (b_state)
    {
        cout << "width 20 square peg fit round hole" << endl;
    }
    else
    {
        cout << "width 20 square peg not fit round hole" << endl;
    }

    return 0;
}