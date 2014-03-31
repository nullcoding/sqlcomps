#ifndef RAMENTRYDIALOG_H
#define RAMENTRYDIALOG_H

#include <QDialog>
#include <QDateTime>
#include "id_class_lists.h"

class RAM_keys;

namespace Ui {
class RAMEntryDialog;
}

class RAMEntryDialog : public QDialog
{
    Q_OBJECT

public:
    RAMEntryDialog(QWidget *parent = 0);
    ~RAMEntryDialog();
    void setupLists();
    RAM_keys * rk;

public slots:
    QString returnData();
    void generateMajorKey();
    void generateMinorKey();
    QString generateUID();

private:
    Ui::RAMEntryDialog *ui;
};

#endif // RAMEntryDialog_H
