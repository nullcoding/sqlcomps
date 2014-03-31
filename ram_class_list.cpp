#include "id_class_lists.h"

RAM_keys::RAM_keys()
{
    date_now = QDate::currentDate();
    catID = QString("01");
    subCatIDs_maj << 13 << 14;

    // Desktop
    subCatIDs_min_cat1 << 40 << 41 << 42 << 43 << 44;
    attrIDs_cat1 << 110 << 111 << 111 << 112 << 110;

    // Laptop
    subCatIDs_min_cat2 << 45 << 46 << 47 << 48 << 49;
    attrIDs_cat2 << 210 << 211 << 211 << 112 << 210;
}

RAM_keys::~RAM_keys()
{

}

int RAM_keys::getMajSubCatID(int index)
{
    this->subcatID_maj = this->subCatIDs_maj[index];
    return this->subcatID_maj;
}

int RAM_keys::getMinSubCatID(int index)
{
    switch (this->subcatID_maj)
    {
    case 13:
        this->subcatID_min = this->subCatIDs_min_cat1[index];
        this->attrID = this->attrIDs_cat1[index];
        return this->subcatID_min;
    case 14:
        this->subcatID_min = this->subCatIDs_min_cat2[index];
        this->attrID = this->attrIDs_cat2[index];
        return this->subcatID_min;
    default:
        this->subcatID_min = this->subCatIDs_min_cat1[index];
        this->attrID = this->attrIDs_cat1[index];
        return this->subcatID_min;
    }
}

int RAM_keys::getLast_cid()
{
    QString cidqdata = QString("SELECT COUNT(*) FROM RAM");
    QSqlQuery cidquery;
    if (!cidquery.exec(cidqdata))
    {
        qDebug() << QString("Error with cid query.");
        qDebug() << cidquery.lastError().text();
        return 0;
    }
    else
    {
        qDebug() << "Number of rows affected: " << cidquery.numRowsAffected();
        this->last_cid = cidquery.numRowsAffected() + 1;
        qDebug() << QString("New cid will be: ") << this->last_cid;
        return this->last_cid;
    }
}

/*
int RAM_keys::getLast_cid()
{
    QString cidqdata = QString("SELECT cid FROM RAM ORDER BY cid ASC");
    QSqlQuery cidquery;
    if (!cidquery.exec(cidqdata))
    {
        qDebug() << QString("Error with cid query.");
        qDebug() << cidquery.lastError().text();
        return 0;
    }
    else
    {
        int last = cidquery.size() - 1;
        qDebug() << last;
        qDebug() << cidquery.value(last);
        this->last_cid = cidquery.value(last).toInt();
        return this->last_cid;
    }
}

int RAM_keys::getLast_uid()
{
    int today = this->date_now.dayOfYear();
    QString uidqdata = QString("SELECT amt FROM daily WHERE day = %1").arg(today,0,10);
    QSqlQuery uidquery;
    if (!uidquery.exec(uidqdata))
    {
        qDebug() << QString("Error with uid query.");
        qDebug() << uidquery.lastError().text();
        return 0;
    }
    else
    {
        this->last_uid = uidquery.value(0).toInt();
        return this->last_uid;
    }
}
*/
QString RAM_keys::genCompID()
{
    QString cidnas = QString("%1").arg(this->last_cid,0,10);
    //int cidl = cidnas.length();
    return QString("null");
}

QString RAM_keys::genUniqID()
{
    if (this->last_uid <= 9)
    {
        return QString("0%1%2").arg(this->last_uid,0,10).arg(this->date_now.toString("yyMMdd"));
    }
    else
    {
        return QString("%1%2").arg(this->last_uid,0,10).arg(this->date_now.toString("yyMMdd"));
    }

}
