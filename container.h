#ifndef CONTAINER_H
#define CONTAINER_H

#include <QMap>
#include <QString>
#include <QDebug>
#include <list>
#include <iostream>
#include <allocator.h>
using namespace std;
enum mainPartsCar{PART_BODY,PART_BUS,PART_TRANSMISSION,PART_COUNT};
//typedef float ulong1;
//В нашем случае TypeKey - это тип перечисления mainPartsCar а TypeDetails - это тип деталей хранимые в дереве
template <class TypeDetails ,class TypeAllocator=Allocator<TypeDetails> >
class Container
{
private:
    TypeAllocator allocator;
    QString containerName;
    //Карта содержащая дерево
long countMainPartDetalis;
    list<list<TypeDetails>* >*detailsMap;
    list<bool >andOrTree;

    //Карта содержащая сойства -и- -или- для каждого поддерева (пока не реализовано)
public:

    struct iterator {
    public:
        typename  list< list<TypeDetails>* >::iterator ptr;
        iterator ( typename list<list< TypeDetails> *>::iterator ptr_):ptr(ptr_) {}
        list< TypeDetails >& operator*() {  return **ptr; }
        // TypeDetails* operator->() { return ptr; }
        list< TypeDetails> * operator++() { return (*++ptr);  }
        list< TypeDetails> * operator--() { return (*--ptr);  }

    bool operator==(const iterator & other) const { return ptr == other.ptr; }
    bool operator!=(const iterator & other) const { return !(*this == other); }


    };

    iterator begin () {
        return detailsMap->begin();
    }
    iterator end () {
        return detailsMap->end();
    }
    Container();

    Container(QString name,int countEl);
    Container(Container &container);
    /*/Положить детали в дерево по соответствующему ключу из перечисления
    * Ключ соответствкет поддереву - те главной части машины(тело,шина,трансмиссия)/*/
    void put(int partOfCar,list< TypeDetails> &listDetails,bool andOrTree=true);
    //Извлечь детали из дерева по соответствующему ключу из перечисления
    list< TypeDetails>* get(int numberSubtree);
    // Найти деталь по имени (вдальнейшем можно организовать поиск деталей по какомуто критерию)
   const  TypeDetails& findByName(QString nameDetail);
    //Количетво деталей в поддереве
    int sizeSubtreeElements(int numberSubtree);
    void showSubtree(int numberSubtree);
    void setAndOr(int numberSubtree, bool andOr){
        typename  list<bool >::iterator itPrev=andOrTree.begin();
        advance(itPrev,numberSubtree);
       *itPrev=andOr;
    }
    bool getAndOr(int numberSubtree){
        typename  list<bool >::iterator itPrev=andOrTree.begin();
        advance(itPrev,numberSubtree);
        return *itPrev;
    }
};
#endif // CONTAINER_H
