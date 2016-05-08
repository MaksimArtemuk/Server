#ifndef BUS_H
#define BUS_H


#include  "abstract_detail.h"
class Bus : public AbstractDetail
{
    double diametr;
    int load;
public:
    Bus(QString name);


};


#endif // BUS_H
