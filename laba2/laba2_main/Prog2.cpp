
#include <iostream>
#include <limits>
#include "Cycloid.h"
#include "menu.h"
using namespace menu;
using namespace Prog2;
int main(int argc, const char * argv[]) {
    Prog2::Cycloid c(1,0,1);
    int q = 0;
    do {
        int  d = dialog();
        menu_t(d,c);
        print("Enter 0 for exit");
        input(q);
    } while (q);
    return 0;
}
