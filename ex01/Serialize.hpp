#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <cstdint>

#include "Data.hpp"

class Serialize
{
private:
    Serialize();
    ~Serialize();
    Serialize(const Serialize &other);
    Serialize &operator=(const Serialize &other);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

uintptr_t Serialize::serialize(Data* ptr)
{
    uintptr_t Adresse = reinterpret_cast<uintptr_t>(ptr);
    return (Adresse);
}

Data *Serialize::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data*>(raw);
    return (ptr);
}





#endif