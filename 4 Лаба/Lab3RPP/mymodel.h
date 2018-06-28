#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QAbstractItemModel>

class MyModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    int rows;
    int columns;
    QList<QList<QVariant>> list;
    QList<QVariant> up_header;
    QList<QVariant> left_header;
    MyModel();
    MyModel(int rows,int columns);
    void setRowCount(int row);
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    //virtual QVariant data(const QModelIndex&) const = 0;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount() const;
    virtual int rowCount() const;
    void addRow();
    virtual bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    //virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
    //virtual QModelIndex index(int row, int column) const;
    virtual QModelIndex parent(const QModelIndex &child) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual bool removeRow(int row, const QModelIndex &parent);
    virtual bool removeRow(int row);
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const;
    virtual bool setHeaderData(int section, Qt::Orientation orientation,
                               const QVariant &value, int role = Qt::EditRole);

};

#endif // MYMODEL_H
