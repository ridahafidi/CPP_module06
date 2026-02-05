#include "Base.hpp"
#include <chrono>
#include <thread>

int main()
{
    Base *ptr = generate();
    identify(ptr);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Base &ref = *generate();
    identify(ref);
    delete ptr;
    delete &ref;
}