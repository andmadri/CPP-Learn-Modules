#include "../incl/Base.hpp"

int main(){

    Base *ptr = generate();
    Base& ptr_ref = *ptr;

    identify(ptr);
    identify(ptr_ref);
   
    delete ptr;
    return 0;
}