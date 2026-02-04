#include "Serialize.hpp"

#include <iostream>

int main()
{
    Data *ptr = new Data;
    uintptr_t Addresse = Serialize::serialize(ptr);


    std::cout << "This is serialized adresse : " <<  "0x" << std::hex <<Addresse << "\nThis is the actual ptr adresse : " << ptr << std::endl;
    Data *receiver = Serialize::deserialize(Addresse);
    std::cout << "This is the deserialized adresse : " << receiver << "\n";

    // my tests:
        std::cout<< "a Adresse in Data :  " <<  ptr << std::endl;
        std::cout<< "b Adresse in Data :  " << &ptr->b  << std::endl;
        std::cout<< "c Adresse in Data :  " <<&ptr->c  << std::endl;
        std::cout<< "p Adresse in Data :  " << &ptr->p << std::endl; 
    // char adresse 
    Data *receiv = ptr;

    std::cout << receiv << "\n";
    uintptr_t int_Addresse = Serialize::serialize(ptr) + sizeof(int);
    receiv = Serialize::deserialize(int_Addresse);

    std::cout << receiv << "\n";

    uintptr_t float_Addresse = Serialize::serialize(ptr ) + sizeof(int) + sizeof(int);
    receiv = Serialize::deserialize(float_Addresse);

    std::cout << receiv << "\n";

    uintptr_t double_Addresse = Serialize::serialize(ptr )+ sizeof(int) + sizeof(int) + sizeof(double);
    receiv = Serialize::deserialize(double_Addresse);

    std::cout << receiv << "\n";

    
}