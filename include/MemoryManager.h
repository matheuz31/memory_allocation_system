#pragma once
#include <map>
#include <typeinfo>


class MemoryManager{
public:
    static std::map<void*, std::string> allocations;
    template<typename T>  //Generic placeholder
    static T* allocate(size_t size){
        T* ptr = new T[size];
        allocations[ptr] = std::string(typeid(T).name()) + "[]";
        std::cout << "Allocated: " << allocations[ptr] << " in " << ptr << std::endl;
        return new T[size];  //return a pointer
    }
    template<typename T>
    static void deallocate(T* ptr){
        if(allocations.find(ptr) != allocations.end()){
            std::cout << "Deallocated: " << allocations[ptr] << " in " << ptr << std::endl;
        }
        delete[] ptr;
    }
    
    static void checkLeaks(){
        if(!allocations.empty()){
            std::cout << "Leak detected:" << std::endl;
            for(auto const& pair : allocations){
                std::cout << " - " << pair.second << "Still allocated in " << pair.first << std::endl;
            }
        }
        else {
            std::cout << "No memory leakage detected." << std::endl;
        }
    }
    
};

std::map<void*, std::string> MemoryManager::allocations;