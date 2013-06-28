#include <iostream>
#include <thread>
#include <vector>

//This function will be called from a thread
void call_from_thread() {
    std::cout << "Hello, World!" << std::endl;
}

void p(std::vector<int> &numbers) {
    // c++11的“高级for循环”，从java的角度
    for (auto &i: numbers) {
        std::cout << "i = " << i << std::endl;

        if (i == 423) i = 999;
    }

    // 通过&引用修改了下标为3的值为999
    std::cout << "numbers[3] = " << numbers[3] << std::endl;
}

void print(int num) {
    std::cout << "num = " << num << std::endl;
}

int main() {
    //Launch a thread
    std::thread t1(call_from_thread);

    //Join the thread with the main thread
    t1.join();

    std::vector<int> numbers;
    numbers.push_back(123);
    numbers.push_back(223);
    numbers.push_back(323);
    numbers.push_back(423);
    numbers.push_back(523);
    numbers.push_back(623);
    numbers.push_back(723);
    numbers.push_back(823);
    p(numbers);

    // lambda表达式
    int num = 123;
    // [&num] 闭包方式访问外部变量
    print([&num](int n) { num += 10; return n + 100; }(num));
    print(num);

    return 0;
}
