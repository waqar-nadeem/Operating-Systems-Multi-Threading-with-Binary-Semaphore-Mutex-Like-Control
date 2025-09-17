#include <iostream>
#include <thread>
#include <semaphore.h>

sem_t sem;
int sharedVar = 0;

void threadFunc(int id) {
    sem_wait(&sem);      
    sharedVar++;
    std::cout << "Thread " << id << " incremented sharedVar to " << sharedVar << "\n";
    sem_post(&sem);    
}

int main() {
    sem_init(&sem, 0, 1); 

    std::thread t1(threadFunc, 1);
    std::thread t2(threadFunc, 2);

    t1.join();
    t2.join();

    sem_destroy(&sem);
    return 0;
}
