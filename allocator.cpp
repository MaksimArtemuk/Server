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
qDebug()<<"hello11:"<<count;
 list<TypeDetails >*t1;
t=new list<list<TypeDetails > *>;
t->assign(count,t1);
//detailsMap.assign(countEl,t);
//andOrTree.assign(countEl,false);
return t;
}
template class Allocator<AbstractDetail> ;
