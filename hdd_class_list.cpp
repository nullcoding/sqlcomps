#include "id_class_lists.h"

HDD_keys::HDD_keys()
{
    date_now = QDate::currentDate();
    catID = QString("00");
    subCatIDs_maj << 11 << 11 << 10;

    // Desktop
    subCatIDs_min_cat1 << 50 << 51 << 52 << 53 << 88 << 88 << 88 << 88;
    attrIDs_cat1 << 100 << 101 << 101 << 101 << 100 << 100 << 100 << 100;

    // Laptop
    subCatIDs_min_cat2 << 54 << 55 << 56 << 57 << 89 << 89 << 89 << 89;
    attrIDs_cat2 << 102 << 103 << 103 << 103 << 102 << 102 << 102 << 102;
}

HDD_keys::~HDD_keys()
{

}

int HDD_keys::getMajSubCatID(int index)
{
    this->subcatID_maj = this->subCatIDs_maj[index];
    return this->subcatID_maj;
}

int HDD_keys::getMinSubCatID(int index)
{
    switch (this->subcatID_maj)
    {
    case 10:
        this->subcatID_min = this->subCatIDs_min_cat1[index];
        this->attrID = this->attrIDs_cat1[index];
        return this->subcatID_min;
    case 11:
        this->subcatID_min = this->subCatIDs_min_cat2[index];
        this->attrID = this->attrIDs_cat2[index];
        return this->subcatID_min;
    default:
        this->subcatID_min = this->subCatIDs_min_cat1[index];
        this->attrID = this->attrIDs_cat1[index];
        return this->subcatID_min;
    }
}

int HDD_keys::getLast_cid()
{
    QString cidqdata = QString("SELECT COUNT(*) FROM HDD");
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
int HDD_keys::getLast_cid()
{
    QString cidqdata = QString("SELECT cid FROM HDD ORDER BY cid ASC");
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
*/
int HDD_keys::getLast_uid()
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

QString HDD_keys::genCompID()
{
    QString cidnas = QString("%1").arg(this->last_cid,0,10);
    int cidl = cidnas.length();
    return QString("null");
}

QString HDD_keys::genUniqID()
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
