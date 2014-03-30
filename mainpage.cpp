#include "mainpage.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    QObject::connect(ui->dropdown, SIGNAL(currentTextChanged(QString)), this, SLOT(determineCurrent(QString)));
    QObject::connect(ui->dropdown, SIGNAL(currentIndexChanged(int)), this, SLOT(refreshModel(int)));
    QObject::connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addHDD()));

    QSqlTableModel *model = setupModel(ui->dropdown->currentIndex());
    ui->mainTable->setModel(model);
}

void MainPage::determineCurrent(QString text)
{
    qDebug() << ui->dropdown->currentText();
    qDebug() << text;
}

void MainPage::refreshModel(int category)
{
    QSqlTableModel *newmodel = setupModel(category);
    ui->mainTable->setModel(newmodel);
}

void MainPage::addHDD()
{
    NewEntryDialog ned;

    if (ned.exec())
    {
        QString queryData = ned.returnData();
        QSqlQuery query;
        qDebug() << queryData;
        if (!query.exec(queryData))
        {
            qDebug() << QString("Error with query.");
            qDebug() << query.lastError().text();
        }
        refreshModel(ui->dropdown->currentIndex());
    }
}

MainPage::~MainPage()
{
    delete ui;
}
