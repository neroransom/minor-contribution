#include "mainwindow.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/skin.qss");
    if(qss.open(QFile::ReadOnly)){
    QString styleSheet = QLatin1String(qss.readAll());
    a.setStyleSheet(styleSheet);
    qss.close();
    }
    MainWindow w;
    w.show();
    return a.exec();
}
