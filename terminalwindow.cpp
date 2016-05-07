#include "terminalwindow.h"

TerminalWindow::TerminalWindow(QWidget *parent) : QWidget(parent)
{
    TerminalWindow::setFixedSize(320, 300);
    TerminalWindow::setWindowTitle("Комплектация автомобиля");

    QFormLayout * formLayout = new QFormLayout;
    QFont labelFont;
    labelFont.setFamily("Sitka Text");
    labelFont.setPixelSize(20);
    TerminalWindow::setFont(labelFont);
    QPalette background = palette();
    background.setColor(backgroundRole(), Qt::white);
    setPalette(background);
    QPixmap statusRed("res/red.png");
    QPixmap statusGreen("res/green.png");

    terminall = new QPushButton;
    terminall->setText("Терминал 1");
    terminal2 = new QPushButton;
    terminal2->setText("Терминал 2");
    terminal3 = new QPushButton;
    terminal3->setText("Терминал 3");
    terminal4 = new QPushButton;
    terminal4->setText("Терминал 4");
    terminal5 = new QPushButton;
    terminal5->setText("Терминал 5");
    terminal6 = new QPushButton;
    terminal6->setText("Терминал 6");

    statusTerminall = new QLabel;
    statusTerminall->setPixmap(statusRed);
    statusTerminall->setFixedSize(40, 40);
    statusTerminall->setMargin(5);
    statusTerminall->setScaledContents(true);
    statusTerminal2 = new QLabel;
    statusTerminal2->setPixmap(statusRed);
    statusTerminal2->setFixedSize(40, 40);
    statusTerminal2->setMargin(5);
    statusTerminal2->setScaledContents(true);
    statusTerminal3 = new QLabel;
    statusTerminal3->setPixmap(statusRed);
    statusTerminal3->setFixedSize(40, 40);
    statusTerminal3->setMargin(5);
    statusTerminal3->setScaledContents(true);
    statusTerminal4 = new QLabel;
    statusTerminal4->setPixmap(statusRed);
    statusTerminal4->setFixedSize(40, 40);
    statusTerminal4->setMargin(5);
    statusTerminal4->setScaledContents(true);
    statusTerminal5 = new QLabel;
    statusTerminal5->setPixmap(statusRed);
    statusTerminal5->setFixedSize(40, 40);
    statusTerminal5->setMargin(5);
    statusTerminal5->setScaledContents(true);
    statusTerminal6 = new QLabel;
    statusTerminal6->setPixmap(statusRed);
    statusTerminal6->setFixedSize(40, 40);
    statusTerminal6->setMargin(5);
    statusTerminal6->setScaledContents(true);

    formLayout->addRow(statusTerminall, terminall);
    formLayout->addRow(statusTerminal2, terminal2);
    formLayout->addRow(statusTerminal3, terminal3);
    formLayout->addRow(statusTerminal4, terminal4);
    formLayout->addRow(statusTerminal5, terminal5);
    formLayout->addRow(statusTerminal6, terminal6);
    setLayout(formLayout);

    connect(terminall, SIGNAL(clicked(bool)), this, SLOT(onClick(bool)));
}

void TerminalWindow::onClick(bool)
{

}
