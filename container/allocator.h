#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <list>
#include <iostream>
using namespace std;
template<class TypeDetails>
class Allocator
{
public:
   list<list<TypeDetails >* > *t;
    Allocator();
list<list<TypeDetails >* >* allocate(int count);
};

#endif // ALLOCATOR_H
