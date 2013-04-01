#include <iostream>

#ifdef __cplusplus
extern "C" {
#include "utils.h"
}
#endif

int main(int argc, char* argv[]) {
    std::cout << "Hello World!!\n";

    int x = 20;
    int y = 40;

    std::cout << x << " + " << y << " = " << add(x, y) << "\n";
    return 0; 
}
