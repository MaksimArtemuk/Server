#ifndef TERMINALWINDOW_H
#define TERMINALWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>

class TerminalWindow : public QWidget
{
    Q_OBJECT
    QPushButton * terminall;
    QPushButton * terminal2;
    QPushButton * terminal3;
    QPushButton * terminal4;
    QPushButton * terminal5;
    QPushButton * terminal6;

    QLabel      * statusTerminall;
    QLabel      * statusTerminal2;
    QLabel      * statusTerminal3;
    QLabel      * statusTerminal4;
    QLabel      * statusTerminal5;
    QLabel      * statusTerminal6;

public:
    TerminalWindow(QWidget *parent = 0);

public slots:
    void onClick(bool);
};

#endif // TERMINALWINDOW_H
