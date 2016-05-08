//---------

#include <QApplication>
#include "server/terminalwindow.h"
#include "container/container.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    TerminalWindow window;
    window.show();
   // testContainer();
    return app.exec();
}
