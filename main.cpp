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
    Container< AbstractDetail,Allocator<AbstractDetail> > *container=new Container< AbstractDetail,Allocator<AbstractDetail> >("con",PART_COUNT);//Создаем контейнер

    list<AbstractDetail> buses,bodies,transmissions;//Списки деталей
    list<AbstractDetail> *buses1,*bodies1,*transmissions1;

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

    /*/Bus bas1("ba1"),bas2("ba2"),bas3("ba3");
    Body body1("bo1"),body2("bo2"),body3("bo3");
    Transmission tr1("tr1"),tr2("tr2"),tr3("tr3");
    buses.push_back(bas1);
        buses.push_back(bas2);
        buses.push_back(bas3);

        bodies.push_back(body1);
        bodies.push_back(body2);
        bodies.push_back(body3);

        transmissions.push_back(tr1);
        transmissions.push_back(tr2);
        transmissions.push_back(tr3);/*/

    qDebug()<<"--------Tr";
    container->put(PART_TRANSMISSION,transmissions);
     qDebug()<<"--------Body";
    container->put(PART_BODY, bodies);
     qDebug()<<"--------Bus";
    container->put(PART_BUS,buses);

    transmissions1=   container->get(PART_TRANSMISSION);
    bodies1=   container->get(PART_BODY);
    buses1=   container->get(PART_BUS);
 qDebug()<<"--------Buses";
    foreach (AbstractDetail detail,*buses1) {
        detail.getNameDetail();
    }

    qDebug()<<"--------Bodies";
    foreach (AbstractDetail detail,*bodies1) {
        detail.getNameDetail();
    }
    qDebug()<<"--------Transmissions";
    foreach (AbstractDetail detail,*transmissions1) {
       detail.getNameDetail();
    }
  qDebug()<<"Test iterator b ";
   Container<AbstractDetail>::iterator it=container->begin(),it2=container->begin();

 list<AbstractDetail>  v1=*it,v2;
++it;
++it2;
/*/ ++it;
 ++it;
 ++it;
 ++it;
 ++it;
 ++it;/*/
 v2=  *(it);
 if(it==it2)qDebug()<<"wwww";

     qDebug()<<"--------";
    foreach (AbstractDetail detail,v1) {
       detail.getNameDetail();
    }
    foreach (AbstractDetail detail,v2) {
       detail.getNameDetail();
    }
 //  (++it);
 //  v2=   *  (++it);
  // v2=   *  (++it);
 //  v2=   * (++it);

  //   v2=   *(--it); v2=   *(--it);
 // v2=   *(--it);
     qDebug()<<"--------111";
  foreach (AbstractDetail detail,v2) {
     detail.getNameDetail();
  }   qDebug()<<"--------111";
 qDebug()<<"Test iterator e ";
 Container< AbstractDetail,Allocator<AbstractDetail> > container1=*container;
 qDebug()<<"///////////////////////";
 container->showSubtree(PART_BODY);
 /*/qDebug()<<"///////////////////////";
/*/
 delete container;

 transmissions1=   container1.get(PART_TRANSMISSION);
 bodies1=   container1.get(PART_BODY);
 buses1=   container1.get(PART_BUS);

qDebug()<<"--------Buse1s";

 foreach (AbstractDetail detail,*buses1) {
     detail.getNameDetail();
 }


 qDebug()<<"--------Bodies1";
 foreach (AbstractDetail detail,*bodies1) {
     detail.getNameDetail();
 }
 qDebug()<<"--------Transmissions1";
 foreach (AbstractDetail detail,*transmissions1) {
    detail.getNameDetail();
 }

  //  ---------------
   // TerminalWindow window;
  //  window.show();

    return app.exec();
}
