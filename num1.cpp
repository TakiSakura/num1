/*
 * c++ namespace 修饰符
 * 创建对象的两种方式
 * 释放堆上对象内存
 * 类外独立函数main（）
 * this指针
 *
 */

// c++ input output stream
#include<iostream>

// c++命名空间，作用域
// 命名空间(namespace)为防止名字冲突提供了更加可控的机制。命名空间分割了全局命名空间，其中每个命名空间是一个作用域。
// 通过在某个命名空间中定义库的名字，库的作者以及用户可以避免全局名字固有的限制。

using namespace std;

// c++ class前没有修饰符
class A {
// 若成员变量不加修饰符，默认为private
// c++类成员修饰符格式为"private:"
private:
    int x;
public:
    void setX(int x) {
        // this是指针，而不是引用
        this->x = x;
    }

    int getX() const {
        return this->x;
    }
};

// c++函数可以孤立、声明在类外
int main(int argc, char *argv[]) {
    // 创建对象的两种方式
    // 为节省存储空间，C++创建对象时仅分配用于保存数据成员的空间，而类中定义的成员函数则被分配到存储空间中的一个公用区域，由该类的所有对象共享。

    // 内存分配是分配到栈中的，由C++缺省创建和撤销，自动调用构造函数和析构函数
    A a;
    // 在堆上分配内存来创建对象的（与上不同）；不同的是，C++用new创建对象时返回的是一个对象指针。
    A *a1 = new A;
    a.setX(0);
    (*a1).setX(1);
    // cout 打印到控制台
    cout << a.getX() << " " << (*a1).getX() << endl;
    // 用new动态创建的对象必须用delete来撤销该对象。只有delete对象才会调用其析构函数。
    delete a1;
    return 0;
}

