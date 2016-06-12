#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QRect rec = QApplication::desktop()->screenGeometry();
    w.setGeometry((rec.width() - 1280) / 2, (rec.height() - 800) / 2, 1280, 800);
    w.show();

    return a.exec();
}
