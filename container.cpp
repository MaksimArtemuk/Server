#include "container.h"
#include "abstract_detail.h"

template <class TypeDetails ,class TypeAllocator>
Container< TypeDetails,TypeAllocator>::Container()
{

}

template <class TypeDetails ,class TypeAllocator>
Container< TypeDetails,TypeAllocator>::Container(Container &container){
 //   qDebug()<<"constrCopy";
    countMainPartDetalis=container.countMainPartDetalis;
    detailsMap=allocator.allocate(countMainPartDetalis);
    andOrTree.assign(countMainPartDetalis,false);
    containerName=container.containerName;
//cout<<"beg"<<endl;
typename list< list<TypeDetails> *> ::iterator itPrev=detailsMap->begin();
    foreach (list<TypeDetails> * listv,*container.detailsMap)
   {
   **itPrev=*listv;
     itPrev++;
    }

  // cout<<"end"<<endl;
}

template <class TypeDetails ,class TypeAllocator>
Container<TypeDetails ,TypeAllocator>::Container(QString name,int countEl):containerName(name),
    countMainPartDetalis(countEl)
{
  detailsMap=   allocator.allocate(countEl);
  andOrTree.assign(countEl,false);
}

template <class TypeDetails ,class TypeAllocator>
void Container< TypeDetails ,TypeAllocator>::put(int numberSubtree,list<TypeDetails>&_list,bool andOr) {
     typename  list< list<TypeDetails>* >::iterator itPrev=detailsMap->begin();
     typename  list<bool >::iterator itPrev1=andOrTree.begin();
     advance(itPrev,numberSubtree);
     advance(itPrev1,numberSubtree);
    **itPrev=_list;
    *itPrev1=andOr;
}

template <class TypeDetails,class TypeAllocator>
list<TypeDetails >* Container< TypeDetails,TypeAllocator>::get(int numberSubtree){
    typename  list< list<TypeDetails> *>::iterator itPrev=detailsMap->begin();
    std::advance(itPrev,numberSubtree);
    return (*itPrev);
}
/*/
template <class TypeDetails,class TypeAllocator>
const TypeDetails& Container< TypeDetails,TypeAllocator>::findByName(QString name){
    foreach (list<TypeDetails*> list,*detailsMap) {
        foreach (TypeDetails *detail,  list) {
            if(*detail==name){qDebug()<<"detailFind"; return *detail;}
        }
    }
}

template <class TypeDetails ,class TypeAllocator>
int Container< TypeDetails,TypeAllocator>::sizeSubtreeElements(int numberSubtree){
    typename  list< list<TypeDetails> >::iterator itPrev;
    std::advance(itPrev,numberSubtree);
    return (*itPrev).size();
}
/*/
template <class TypeDetails ,class TypeAllocator>
void Container< TypeDetails,TypeAllocator>::showSubtree(int numberSubtree){
    typename  list< list<TypeDetails>* >::iterator itPrev=detailsMap->begin();
    std::advance(itPrev,numberSubtree);
    foreach (TypeDetails detail,**itPrev)
        cout<<detail<<endl;
}

template <class TypeDetails ,class TypeAllocator>
Container<TypeDetails ,TypeAllocator>::~Container(){
   foreach (list<TypeDetails>*listv, *detailsMap) {

       listv->clear();
     //  delete listv;
    }

   detailsMap->clear();
}

template class Container<AbstractDetail,Allocator<AbstractDetail> >;
