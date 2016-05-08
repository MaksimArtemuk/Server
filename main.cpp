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
   testContainer();
    return app.exec();
}
