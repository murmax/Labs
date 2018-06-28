#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QModelIndex>
#include <QStringList>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QSaveFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setLayout(ui->MainLayout);
    QStringList cmbBox={"Первый","Второй","Четвертый","Крайний"};
    ui->formCb->addItems(cmbBox);
    QStringList headers={"Имя","Фамилия","Телефон", "Отдел"};
    model = new MyModel(4,4);

    for (int j=0;j<headers.length();j++){
        model->setHeaderData(j,Qt::Horizontal,headers.at(j));
    }
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setModel(model);
    qDebug()<<"1";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAdd_clicked()
{
    qDebug()<<"2";
    model->insertRows(model->rowCount(),1);
    QVariantList list = getForm();
    qDebug()<<"3";
    for (int i=0;i<model->columnCount();i++)
    {
        qDebug()<<"4";
        model->setData(model->index(model->rowCount()-1,i),list.at(i));
    }
}

void MainWindow::on_btnSave_clicked()
{
    QFileDialog fldg;
    QFile file(fldg.getSaveFileName());
    file.open(QFile::WriteOnly);
    QTextStream stream(&file);
    qDebug()<<"5";
    for (int i=0;i<model->rowCount();i++){
        for (int j=0;j<model->columnCount();j++)
        {
            qDebug()<<"6";
            stream<<"\""<<model->data(model->index(i,j)).toString().replace("\"","\"\"")<<"\";";
        }
        stream<<"\r\n"<<endl;
    }
}

void MainWindow::on_btnDel_clicked()
{
    //QItemSelection sel ( ui->tableView->selectionModel()->selection());
    //if (sel.indexes().size()!=1) qDebug()<<"WTF??";
   // else
        if ((selected.row()>=0)&&(model->rowCount()>selected.row()))
            model->removeRow(selected.row());
}

QVariantList MainWindow::getForm()
{
    QVariantList list;
    list.append(ui->formLn1->text());
    list.append(ui->formLn2->text());
    list.append(ui->formLn3->text());
    list.append(ui->formCb->currentText());
    return list;
}

/*void MainWindow::on_pushButton_clicked()
{
//deprecated
}*/

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    qDebug()<<"Click "<<index.row()<<" "<<index.column();

    ui->formLn1->setText(model->data(model->index(index.row(),0)).toString());
    ui->formLn2->setText(model->data(model->index(index.row(),1)).toString());
    ui->formLn3->setText(model->data(model->index(index.row(),2)).toString());
    ui->formCb->setCurrentText(model->data(model->index(index.row(),3)).toString());
    selected = index;

}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
 //   qDebug()<<"Activate "<<index.row()<<" "<<index.column();
}

void MainWindow::on_tableView_entered(const QModelIndex &index)
{
    qDebug()<<"Entered "<<index.row()<<" "<<index.column();
    ui->formLn1->setText(model->data(model->index(index.row(),0)).toString());
    ui->formLn2->setText(model->data(model->index(index.row(),1)).toString());
    ui->formLn3->setText(model->data(model->index(index.row(),2)).toString());
    ui->formCb->setCurrentText(model->data(model->index(index.row(),3)).toString());
    selected = index;
}

void MainWindow::on_BtnSave_clicked()
{
    //qDebug()<<"SELECTION SIZE: "<<ui->tableView->selectionModel()->selection().size();
    //if (ui->tableView->selectionModel()->selection().size()==1)
    //{
       QModelIndex index = selected;//ui->tableView->selectionModel()->selection().at(0).indexes().at(0);
       qDebug()<<"SELECTION INDEX: "<<index.row()<<" "<<index.column();
       QVariantList list = getForm();
       for (int i=0;i<model->columnCount();i++)
       {
           model->setData(model->index(index.row(),i),list.at(i));
       }
   // }
}

void MainWindow::on_pushButton_clicked()
{
    //DEBUG BTN
    for (int i=0;i<model->rowCount();i++)
        for (int j=0;j<model->columnCount();j++)
            qDebug()<<"i: "<<i<<" j: "<<j<<" "<<model->data(model->index(i,j)).toString();
}
