#include "dialog.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //add
       QFile qss("D:\\PROGRAM-CPP\\original\\User-interface\\Aqua.qss");
       if( qss.open(QFile::ReadOnly))
       {
         qDebug("open success");
         QString style = QLatin1String(qss.readAll());
         a.setStyleSheet(style);
         qss.close();
        }
         else
        {
          qDebug("Open failed");
        }
       //
       Dialog w;
       w.show();
       return a.exec();
}
