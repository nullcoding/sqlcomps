#include "model.h"

QSqlTableModel *setupModel(int category)
{
    QSqlTableModel *model = new QSqlTableModel();
    switch(category)
    {
        case 0:
        {
            model->setTable("HDD");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->select();
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Brand"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("Size"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("Interface"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("Form Factor"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Added"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("Serial"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("Comments"));
            model->setHeaderData(8, Qt::Horizontal, QObject::tr("uid"));
            model->setHeaderData(9, Qt::Horizontal, QObject::tr("cid"));
        }
        break;
        case 1:
    {
        model->setTable("RAM");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Brand"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Size"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Form Factor"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Interface"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Speed"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Added"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Comments"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("uid"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("cid"));
    }
        break;
        case 2:
    {
    }
        break;
        case 3:
    {
    }
        break;
    }


    return model;
}

void initializeModel(QSqlTableModel *model)
{
    model->setTable("HDD");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Brand"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Size"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Interface"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Form Factor"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Added"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Comments"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("uid"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("cid"));
}

QTableView *createView(QSqlTableModel *model)
{
    QTableView *view = new QTableView();
    view->setModel(model);
    return view;
}
