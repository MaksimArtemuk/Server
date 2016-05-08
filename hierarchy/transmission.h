#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include "abstract_detail.h"
class Transmission:public AbstractDetail
{
    QString type;
    QString drive;
public:
    Transmission(QString name);


};

#endif // TRANSMISSION_H
