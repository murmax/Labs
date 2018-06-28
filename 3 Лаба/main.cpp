//#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QStringList>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#define Length 4

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    QTableView w;
    QStringList headers={"Идентификатор","Имя","Отчество","Телефон","Должность","Зарплата"};
    QStandardItemModel model(1,1,&w);

    for (int j=0;j<headers.length();j++){
        model.setHeaderData(j,Qt::Horizontal,headers.at(j));
    }
    w.setSelectionMode(QAbstractItemView::SingleSelection);
    w.setModel(&model);
    QFileDialog fldg;
    QFile file(fldg.getOpenFileName());
    file.open(QFile::ReadOnly);
    QString str = file.readAll()+',';
    file.close();
    char x=0,y=0;
    int last=0;
    bool flag= false;
    for (int i=0;i<str.length();i++)
    {
        //qDebug()<<"DEBUG: "<<"Symbol"<<str[i]<<" Flag:"<<(int)flag;
        switch ( (str[i]).toLatin1())
        {
            case ',':
                if (!flag){
                    if (y+1==model.columnCount())
                    {
                        model.setColumnCount(model.columnCount()+1);
                    }
                    model.setData(model.index(x,y++),str.mid(last, i-last));
                    //qDebug()<<"DEBUG: "<<str.mid(last, i-last)<<" X:"<<(int)x<<" Y:"<<(int)y;
                    last = i+1;
                }
            break;
            case '\xd':
            //qDebug()<<"DEBUG: "<<"!!!!";
            if (!flag){
               // qDebug()<<"DEBUG: "<<"!!!!2";

                model.setData(model.index(x,y++),str.mid(last, i-last));
                //qDebug()<<"DEBUG: "<<str.mid(last, i-last)<<" X:"<<(int)x<<" Y:"<<(int)y;
                last = i+1;
                if (x+1==model.rowCount())
                {
                    x++;
                    y=0;

                    model.setRowCount(model.rowCount()+1);
                }
            }
        break;
            case '"':
                if (flag)
                {
                    if (str[i+1]=='"')
                    {
                        str.remove(i,1);
                    }
                    else
                    {
                        flag=false;
                        str.remove(i--,1);
                    }
                }
                else
                {
                    flag=true;
                    str.remove(i--,1);
                }
            break;
        }

    }




    w.show();

    return a.exec();
}
