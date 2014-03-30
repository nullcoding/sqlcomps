#ifndef NEWENTRYDIALOG_H
#define NEWENTRYDIALOG_H

#include <QDialog>
#include <QDateTime>
#include "id_class_lists.h"

class HDD_keys;

namespace Ui {
class NewEntryDialog;
}

class NewEntryDialog : public QDialog
{
    Q_OBJECT

public:
    NewEntryDialog(QWidget *parent = 0);
    ~NewEntryDialog();
    void setupLists();
    HDD_keys * hk;

public slots:
    QString returnData();
    void generateMajorKey();
    void generateMinorKey();
    QString generateUID();

private:
    Ui::NewEntryDialog *ui;
};

#endif // NEWENTRYDIALOG_H
