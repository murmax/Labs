#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QStandardItemModel>
#include "mymodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();

    void on_btnSave_clicked();

    void on_btnDel_clicked();

    QVariantList getForm();


    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_entered(const QModelIndex &index);

    void on_BtnSave_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MyModel* model;
    QModelIndex selected;

};

#endif // MAINWINDOW_H
