// Nomor 21

#include <iostream>
using namespace std;

class GrandBase {
     public:
          virtual void show() { std::cout << "grandbase::show()\n"; }
};

class Base1 : virtual public GrandBase {
     public:
          virtual void print() { std::cout << "base1::print()\n"; }
};

class Base2 : virtual public GrandBase {
     public:
          virtual void print() { std::cout << "base2::print()\n"; }
          void show() override { std::cout << "base2::show()\n"; }
};

class Derived : public Base1, public Base2 {
     public:
          void print() override { std::cout << "derived::print()\n"; }
          void show() override { std::cout << "derived::show()\n"; }
};

int main() {
     Derived* d = new Derived();
     Base1& b1 = *d;
     Base2 b2 = *d;
     GrandBase& gb = *d;

     cout << "line 31" << endl;
     b1.print(); // Line 31

     cout << "line 32" << endl;
     b2.print(); // Line 32

     cout << "line 33" << endl;
     gb.show(); // Line 33

     cout << "line 34" << endl;
     d->show(); // Line 34
     delete d;
     return 0;
     // …
}