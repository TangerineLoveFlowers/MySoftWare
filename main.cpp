#include "software.h"
#include "mytitlebar.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Software w;
    w.show();

    //MyTitleBar *mt=new MyTitleBar();
    //mt->show();
    return a.exec();
}
