#include <iostream>
#include <MemoryManager.h>

int main() {
    std::cout << "Manager memory System" << std::endl;

    char* ptr = MemoryManager::allocate<char>(10); 
    MemoryManager::deallocate(ptr);

    MemoryManager::checkLeaks();

    return 0;

}