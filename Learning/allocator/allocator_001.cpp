#include <iostream>
#include <string>
#include <memory>

// file nay se overrite new and delete operator de show ra duoc so luong memory 
// da duoc allocate

struct AllocationMetrics {
    uint32_t TotalAllocated = 0;
    uint32_t TotalFree = 0;
    uint32_t CurrentUsage (){ return TotalAllocated - TotalFree; }
};

static AllocationMetrics s_AllocationMetrics;

// overwrite "new"
void* operator new(size_t size) {
    // std::cout << "Alloacting " << size << " bytes\n"; 
    s_AllocationMetrics.TotalAllocated += size;
    return malloc(size);
}

// overwrite "delete" or unique_ptr destructor
void operator delete(void* memory, size_t size) {
    // std::cout << "Free: " << size << " bytes\n";
    s_AllocationMetrics.TotalFree += size;
    free(memory);
}

struct Object {
    int x, y, z;
};

static void PrintMemoryUsage() {
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

int main() {
    PrintMemoryUsage();
    std::string string = "dang";
    // Object* obj = new Object;
    {
        PrintMemoryUsage();
        std::unique_ptr<Object> obj = std::make_unique<Object>();
        PrintMemoryUsage();
    }
    PrintMemoryUsage();
    
}
