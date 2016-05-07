#include <QApplication>
#include "terminalwindow.h"
#include "container.h"
#include "abstract_detail.h"
#include "bus.h"
#include "body.h"
#include "transmission.h"
int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    qDebug()<<"99999";
    Container< AbstractDetail,Allocator<AbstractDetail> > container("con",PART_COUNT);//Создаем контейнер

    list<AbstractDetail> buses,bodies,transmissions;//Списки деталей
    list<AbstractDetail> *buses1,*bodies1,transmissions1;

    // Заполняем списки
    buses.push_back(*new Bus("bus1"));
    buses.push_back(*new Bus("bus2"));
    buses.push_back(*new Bus("bus3"));

    bodies.push_back(*new Body("body1"));
    bodies.push_back(*new Body("body2"));
    bodies.push_back(*new Body("body3"));

    transmissions.push_back(*new Transmission("transmission1"));
    transmissions.push_back(*new Transmission("transmission1"));
    transmissions.push_back(*new Transmission("transmission1"));
    qDebug()<<"--------Tr";
    container.put(PART_TRANSMISSION,transmissions);
     qDebug()<<"--------Body";
    container.put(PART_BODY, bodies);
     qDebug()<<"--------Bus";
    container.put(PART_BUS,buses);

    transmissions1=   *container.get(PART_TRANSMISSION);
    bodies1=   container.get(PART_BODY);
    buses1=   container.get(PART_BUS);
 qDebug()<<"--------Buses";
    foreach (AbstractDetail detail,*buses1) {
        detail.getNameDetail();
    }

    qDebug()<<"--------Bodies";
    foreach (AbstractDetail detail,*bodies1) {
        detail.getNameDetail();
    }
    qDebug()<<"--------Transmissions";
    foreach (AbstractDetail detail,transmissions1) {
       detail.getNameDetail();
    }
    Container<AbstractDetail>::iterator it=container.begin();
 list<AbstractDetail>  v1=*it,v2;
    v2=  *(++it);
    qDebug()<<"--------";
    foreach (AbstractDetail detail,v1) {
       detail.getNameDetail();
    }
    foreach (AbstractDetail detail,v2) {
       detail.getNameDetail();
    }

  //  ---------------
   // TerminalWindow window;
  //  window.show();

    return app.exec();
}
