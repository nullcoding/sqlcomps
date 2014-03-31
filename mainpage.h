#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
//#include "dbg.h"
#include "model.h"
#include "newentrydialog.h"
#include "ramentrydialog.h"
#include "id_class_lists.h"

class NewEntryDialog;
class RAMEntryDialog;
class HDD_keys;
class RAM_keys;

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    int category;
    ~MainPage();

public slots:
    void determineCurrent(QString text);
    void refreshModel(int category);
    void addNewComp();
    void addHDD();
    void addRAM();

    // Debugging

    void countHDD();
    void countRAM();
    void countALL();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
