#include "allocator.h"
#include <QDebug>
#include <iostream>
#include <abstract_detail.h>
using namespace std;
template <class TypeDetails>
Allocator< TypeDetails>::Allocator()
{

}

template <class TypeDetails>
list<list<TypeDetails > *>* Allocator<TypeDetails>::allocate(int count){
//qDebug()<<"hello11:"<<count;
t=new list<list<TypeDetails > *>;
for(int i=0;i<count;i++)
   t->push_back(new list<TypeDetails>);

return t;
}
template class Allocator<AbstractDetail> ;
