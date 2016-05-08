#ifndef ABSTRACTDETAIL_H
#define ABSTRACTDETAIL_H
#include <QString>
#include <QDebug>
#include <ostream>
using namespace std;
class AbstractDetail
{
private:
    QString nameDetail;
    int price;
    QString munufacturer;
    int mass;
public:
    AbstractDetail();
    void setNameDetail(QString name){
        nameDetail=name;
    };
    QString getNameDetail(){
        qDebug()<<nameDetail;
        return nameDetail;
    }
  friend  int operator==(const  AbstractDetail&detail,const QString str)
    {
      return detail.nameDetail == str;
    }
  friend  bool operator==(const  AbstractDetail&detail,const  AbstractDetail&detail1)
    {
      return detail.nameDetail == detail1.nameDetail;
    }
  friend  bool operator!=(const  AbstractDetail&detail,const  AbstractDetail&detail1)
    {
     // qDebug()<<"***********";
     qDebug()<<detail.nameDetail <<" "<<detail1.nameDetail<<endl;
      return detail.nameDetail != detail1.nameDetail;
    }
 friend ostream& operator<<(ostream& os, const AbstractDetail&detail)
  {
      os << detail.nameDetail.toStdString() ;
      return os;
  }
};

#endif // ABSTRACTDETAIL_H
