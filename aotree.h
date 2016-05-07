#ifndef AOTREE_H
#define AOTREE_H

#include <list>
using std::list;

template <class T>
class AOTree {
 public:
    AOTreeItem * Insert(AOTreeItem * item, int index, T data);
    void Remove(AOTreeItem * item, int index);

    enum ItemType {And, Or};
    class AOTreeItem {
        ItemType type;
        list <AOTreeItem *> subTree;
        T data;
    };
 private:



};

#endif // AOTREE_H
