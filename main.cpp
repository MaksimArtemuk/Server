#include <QApplication>
#include "terminalwindow.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    TerminalWindow window;
    window.show();

    return app.exec();
}
