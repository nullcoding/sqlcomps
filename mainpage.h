#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "model.h"
#include "newentrydialog.h"
#include "id_class_lists.h"

class NewEntryDialog;
class HDD_keys;

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();

public slots:
    void determineCurrent(QString text);
    void refreshModel(int category);
    void addHDD();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
