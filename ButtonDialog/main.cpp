#include "cbuttondig.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CButtonDIg w;

    w.setWindowTitle("Dialog test");

    w.show();
    return QApplication::exec();
}
