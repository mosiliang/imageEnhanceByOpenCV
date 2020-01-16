#include "imageenhance.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    imageEnhance w;
    w.show();

    return a.exec();
}
