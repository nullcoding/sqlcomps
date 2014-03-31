#include "mainpage.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    QObject::connect(ui->dropdown, SIGNAL(currentTextChanged(QString)), this, SLOT(determineCurrent(QString)));
    QObject::connect(ui->dropdown, SIGNAL(currentIndexChanged(int)), this, SLOT(refreshModel(int)));
    QObject::connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addNewComp()));
    QObject::connect(ui->actionCount_HDD, SIGNAL(triggered()), this, SLOT(countHDD()));
    QObject::connect(ui->actionCount_RAM, SIGNAL(triggered()), this, SLOT(countRAM()));

    this->category = ui->dropdown->currentIndex();
    QSqlTableModel *model = setupModel(category);
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
    this->category = ui->dropdown->currentIndex();
}

void MainPage::addNewComp()
{
    switch(this->category)
    {
    case 0:
    {
        addHDD();
    }
        break;
    case 1:
    {
        addRAM();
    }
        break;
    }
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

void MainPage::addRAM()
{
    RAMEntryDialog red;

    if (red.exec())
    {
        QString queryData = red.returnData();
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

void MainPage::countHDD()
{
    QString cidqdata = QString("SELECT * FROM HDD");
    QSqlQuery * cidquery = new QSqlQuery(cidqdata);
    qDebug() << "Number of rows affected in HDD: " << cidquery->numRowsAffected();
}

void MainPage::countRAM()
{
    QString cidqdata = QString("SELECT * FROM RAM");
    QSqlQuery * cidquery = new QSqlQuery(cidqdata);
    qDebug() << "Number of rows affected in RAM: " << cidquery->numRowsAffected();
}

void MainPage::countALL()
{

}

MainPage::~MainPage()
{
    delete ui;
}
