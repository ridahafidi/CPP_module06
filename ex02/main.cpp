#include "Base.hpp"


int main()
{
    std::srand(std::time(0));
    Base *ptr = generate();
    identify(ptr);
    Base &ref = *generate();
    identify(ref);
    delete ptr;
    delete &ref;
}