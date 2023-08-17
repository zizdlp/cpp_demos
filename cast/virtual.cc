#include <iostream>

class Shape {
    public:
        virtual void draw(){std::cout<<"call Shape draw"<<std::endl;};
};
class PureVirtualShape { //有纯虚函数未实现，则为抽象类。必须实现对应方法才能使用对象
    public:
        virtual void pure_draw()=0;
};

class Rect:public Shape,public PureVirtualShape {
    public:
        void draw() override { // should add override
            std::cout<<"call Rect draw"<<std::endl;
        }
        void rect_unique() {
            std::cout<<"call rect_unique"<<std::endl;
        }
        void pure_draw() override { 
            std::cout<<"call pure_draw"<<std::endl;
        }
};


int main(){
    Rect rect;
    rect.draw(); //call rect draw;
    rect.pure_draw();
    Shape shape;
    shape.draw(); //call shape draw;

    Shape * cast_r2s= new Rect();// 调用赋值构造，右边实质存在子类资源
    cast_r2s->draw();
    // cast_r2s->rect_unique();// 不存在

    PureVirtualShape*cst_r2vs = new Rect();//运行时
    cst_r2vs->pure_draw();

    [[maybe_unused]] auto b = new Rect();
    [[maybe_unused]] auto a = b;
    [[maybe_unused]] auto c= new Shape(); 
    [[maybe_unused]] Rect& new_d = dynamic_cast<Rect&>(*a);  // downcast,必须是多态的,虽然编译不报错，运行时会出错
}