#include "software.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Software w;
    w.show();
    return a.exec();
}
