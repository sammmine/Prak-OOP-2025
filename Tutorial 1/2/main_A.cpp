// cons 1
// cons 2
// ccons 1
// cassign 1 = 2
// show 2
// dest 2
// dest 2
// dest 1

#include "A.hpp"

int main() {
    A x('1');
    A y('2');
    A z(x);
    z = y;
    z.show();
}