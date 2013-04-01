#include <iostream>

#ifdef __cplusplus
extern "C" {
#include "utils1.h"
}
#endif

int main(int argc, char* argv[]) {
    std::cout << "Hello World!!\n";

    int x = 20;
    int y = 40;

    std::cout << x << " + " << y << " = " << add1(x, y) << "\n";
    return 0; 
}
