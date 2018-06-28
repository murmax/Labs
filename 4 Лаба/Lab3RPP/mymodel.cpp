#include "mymodel.h"
#include <QDebug>

MyModel::MyModel()
{

}

MyModel::MyModel(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    QVariant smth= "";
    for (int i=0;i<rows;i++)
    {
        QList<QVariant> ls;
        for (int j=0;j<columns;j++)
        {
            ls.append(smth);
        }
        list.append(ls);
    }
}

void MyModel::setRowCount(int row)
{
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    return list.at(index.row()).at(index.column());
    else return QVariant();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return columns;
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return rows;
}

int MyModel::columnCount() const
{
    return columns;
}

int MyModel::rowCount() const
{

    //if (list.length()!=rows) qDebug()<<"POLUNDRA_ROWS!!";
    return rows;
}

void MyModel::addRow()
{
    beginInsertRows(createIndex(0,0,(void*)NULL),0,rows);
    rows++;
    QVariant smth= "";
    QList<QVariant> ls;
    for (int j=0;j<columns;j++)
    {
        ls.append(smth);
    }
    list.append(ls);
    endInsertRows();
}

bool MyModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row+count-1);
    for(int i=0;i<count;i++)
    {
        rows++;
        QVariant smth= "";
        QList<QVariant> ls;
        for (int j=0;j<columns;j++)
        {
            ls.append(smth);
        }
        list.append(ls);
    }
    endInsertRows();
}

QModelIndex MyModel::index(int row, int column, const QModelIndex &parent) const
{
    //qDebug()<<"INDEX should be: "<<row<<" "<<column;
    return createIndex(row,column,(quintptr)NULL);//*index;
}

QModelIndex MyModel::parent(const QModelIndex &child) const
{
    return createIndex((int)-1,(int)-1,(void*)NULL);
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug()<<"INDEX: "<<index.row()<<" "<<index.column();
    emit layoutAboutToBeChanged();
    try
    {
        list[index.row()][index.column()] = value;
        emit layoutChanged();
        return true;
    }
    catch(...)
    {
        return false;
    }
}

bool MyModel::removeRow(int row, const QModelIndex &parent)
{
    try
    {
        beginRemoveRows(QModelIndex(),row,row);
        list.removeAt(row);
        rows--;
        endRemoveRows();
        return true;
    }
    catch(...)
    {
        return false;
    }
}

bool MyModel::removeRow(int row)
{
    try
    {
        beginRemoveRows(QModelIndex(),row,row);
        list.removeAt(row);
        rows--;
        endRemoveRows();
        return true;
    }
    catch(...)
    {
        return false;
    }
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role==Qt::DisplayRole)
    {
        if (orientation == Qt::Orientation::Horizontal)
        {
            return up_header[section];
        }
        else if (orientation == Qt::Orientation::Vertical)
        {
            return left_header[section];
        }
    }
}

bool MyModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (role==Qt::DisplayRole)
    {
        if (orientation == Qt::Orientation::Horizontal)
        {
            return !(up_header[section]=value).isNull();
        }
        else if (orientation == Qt::Orientation::Vertical)
        {
            return !(left_header[section]=value).isNull();
        }
    }
    return false;
}
