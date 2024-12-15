#include "../incl/Base.hpp"
#include "../incl/A.hpp"
#include "../incl/B.hpp"
#include "../incl/C.hpp"

Base* random_class(int num){
    switch(num) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
    }
    return nullptr;
}

Base* generate(void){
    std::srand(std::time(0));
    int random_int =  std::rand() % 3;
    return random_class(random_int);
}

void identify(Base* p){
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unkown" << std::endl;
    }
}

void identify(Base& p){
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (const std::bad_cast& e){}
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (const std::bad_cast& e){}
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (const std::bad_cast& e) {}
}