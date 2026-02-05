#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base::~Base()
{
    std::cout << "Base destructor called\n";
}


Base *generate(void)
{
    std::srand(std::time(0));
    short trigger = std::rand() % 3;
    Base *b = nullptr;
    if (!trigger)
        b = new A;
    else if (1 == trigger)
        b = new B;
    else if (2 == trigger)
        b = new C;
    return(b);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "This is : A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "This is : B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "This is : C\n";
    else
        std::cerr << "This pointer dosen't point to any derived subobject\n";
}

void identify(Base& p)
{
    try
    {
       (void)dynamic_cast<A&>(p);
        std::cout << "This is : A\n";
        return;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << " Couldn't Cast To A" << std::endl;
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "This is : B\n";
        return;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << " Couldn't Cast To B"  << std::endl;
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "This is : C\n";
        return;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what()  << " Couldn't Cast To C" << std::endl;
    }
}