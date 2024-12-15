#include "../incl/Serializer.hpp"

int main(){
    uintptr_t p;
    Data data;

    data.x = 5;
    data.y = 6;
    data.c = 'H';
    data.b = false;

    p = Serializer::serialize(&data);
    std::cout << "numerical equivalent to pointer to oirginal object: " << p << std::endl;
    Data* deserialize_ptr = Serializer::deserialize(p);
    if (deserialize_ptr == &data) {
        std::cout << "return value of deserialize() compares equal to original pointer" << std::endl;
    } else {
        std::cout << "return value of deserialize() is not equal to original pointer" << std::endl;
    }
    return 0;
}