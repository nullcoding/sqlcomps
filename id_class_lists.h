#ifndef ID_CLASS_LISTS_H
#define ID_CLASS_LISTS_H

#include "db.h"
#include <QDate>

class HDD_keys
{
//    Q_OBJECT

public:

    HDD_keys();
    ~HDD_keys();

    QString catID;
    int subcatID_maj;
    int subcatID_min;
    int attrID;

    QString comp_ID;
    QString unique_ID;

    QDate date_now;
    QDate date_added;
    QDate date_modified;

    int last_cid;
    int last_uid;

    QList<int> subCatIDs_maj;
    //int subCatIDs_maj[] = {11, 11, 10};

    // Desktop
    QList<int> subCatIDs_min_cat1;
    QList<int> attrIDs_cat1;
    //int subCatIDs_min_cat1[] = {50, 51, 52, 53, 88, 88, 88, 88};
    //int attrIDs_cat1[] = {100, 101, 101, 101, 100, 100, 100, 100};

    // Laptop
    QList<int> subCatIDs_min_cat2;
    QList<int> attrIDs_cat2;
    //int subCatIDs_min_cat2[] = {54, 55, 56, 57, 89, 89, 89, 89};
    //int attrIDs_cat2[] = {102, 103, 103, 103, 102, 102, 102, 102};

    int getLast_cid();
    int getLast_uid();

    int getMajSubCatID(int index);
    int getMinSubCatID(int index);

    QString genCompID();
    QString genUniqID();
};

class RAM_keys
{
//    Q_OBJECT

public:

    RAM_keys();
    ~RAM_keys();

    QString catID;
    int subcatID_maj;
    int subcatID_min;
    int attrID;

    QString comp_ID;
    QString unique_ID;

    QDate date_now;
    QDate date_added;
    QDate date_modified;

    int last_cid;
    int last_uid;

    QList<int> subCatIDs_maj;

    // Desktop
    QList<int> subCatIDs_min_cat1;
    QList<int> attrIDs_cat1;

    // Laptop
    QList<int> subCatIDs_min_cat2;
    QList<int> attrIDs_cat2;

    int getLast_cid();
    int getLast_uid();

    int getMajSubCatID(int index);
    int getMinSubCatID(int index);

    QString genCompID();
    QString genUniqID();
};
#endif // ID_CLASS_LISTS_H
