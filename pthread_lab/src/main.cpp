#include <pthread.h>
#include <iostream>

void * hello(void*)
{
    sleep(2);
    std::cout << "Hello\n";
    
    return NULL;
}

void * world(void*)
{
    sleep(3);
    std::cout << "World!!\n";

    return NULL;
}

int main(void)
{
    // 声明两个线程
    pthread_t hello_t, world_t;

    // 创建一个新线程
    pthread_create(&hello_t, NULL, hello, NULL);
    
    // 使主线程等待hello_t线程结束,主线程会阻塞
    //pthread_join(hello_t, NULL);
   
    pthread_create(&world_t, NULL, world, NULL);

    //pthread_join(world_t, NULL);

    std::cout << "main thread!\n";
    sleep(5);
    return 0;
}
