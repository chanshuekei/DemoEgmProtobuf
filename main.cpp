#include "egmprotobufwin.h"

#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Thinking Over The Moon And Typing Under The Moon.";
    EgmProtobufWin w;
    w.show();
    return a.exec();
}
