#ifndef DB_H
#define DB_H

#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

static int HDD = 0;
static int RAM = 1;
static int ODD = 2;
static int FDD = 3;

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("54.225.236.186");
    db.setDatabaseName("components");
    if (!db.open(QString("remote"), QString("remotepass"))) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        qDebug() << "Database response: " << db.lastError().databaseText();
        qDebug() << "Driver response: " << db.lastError().driverText();
        return false;
    }
    return true;
}

#endif
