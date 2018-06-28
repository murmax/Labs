#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QStringList>
#define Length 10

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    QTableView w;
    QStringList headers={"Идентификатор","Имя","Отчество","Телефон","Должность","Зарплата"};
    QStandardItemModel model(Length,headers.length(),this);

    for (int j=0;j<headers.length();j++){
        model->setHeaderData(j,Qt::Horizontal,headers.at(j));
    }
    w.setSelectionMode(QAbstractItemView::SingleSelection);
    w.setModel(model);
    QModelIndex index;
    for (int i=0;i<Length;i++)
    {
        index=model.index(i,1);
        model.setData(index,"ID"+i);
        index=model.index(i,2);
        model.setData(index,"Name "+(char)i);
        index=model.index(i,3);
        model.setData(index,"Partonymic "+(char)(127 - i));
        index=model.index(i,4);
        model.setData(index,"8 800 555 "+i+"5 35");
        index=model.index(i,5);
        model.setData(index,QString("Менеджер среднего звена"));
        index=model.index(i,6);
        model.setData(index,i*5000+10000);
    }




    w.show();

    return a.exec();
}
