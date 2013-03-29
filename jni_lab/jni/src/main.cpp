#include <iostream>
#include "random.h"

int main(void) {
    std::cout << "Hello World!!!!/n";

    IRandom *random = new IRandom();
    std::cout << "random() -- " << random->random() << "\n";

    delete random;
}
