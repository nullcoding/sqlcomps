#include "ramentrydialog.h"
#include "ui_ramentrydialog.h"
#include "ram_class_list.cpp"

RAMEntryDialog::RAMEntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RAMEntryDialog)
{
    ui->setupUi(this);
    setupLists();
    rk = new RAM_keys();
}

void RAMEntryDialog::setupLists()
{
    QStringList sizes;
    QStringList interfaces;
    QStringList formfactors;

    sizes << "8" << "16" << "32" << "64" << "128" << "256" << "512" << "1024" << "2048" << "4096" << "8192" << "16384" << "32768";
    interfaces << "SYNCH" << "DDR" << "DDR2" << "DDR3" << "OTHER";
    formfactors << "Laptop" << "Desktop";

    ui->sizeBox->addItems(sizes);
    ui->interfaceBox->addItems(interfaces);
    ui->formfacBox->addItems(formfactors);
}

void RAMEntryDialog::generateMajorKey()
{

}

void RAMEntryDialog::generateMinorKey()
{

}

QString RAMEntryDialog::generateUID()
{
    return QString("fuck");
}

QString RAMEntryDialog::returnData()
{
    rk->getMajSubCatID(ui->formfacBox->currentIndex());
    rk->getMinSubCatID(ui->interfaceBox->currentIndex());
    int lastcid = rk->getLast_cid();
    QString cid_as = QString("%1").arg(lastcid, 4, 10, QChar('0')).toUpper();
    qDebug() << QString("cid as string: ") << cid_as;
    QString cidstr = QString("%1%2%3%4-%5").arg(rk->catID).arg(rk->subcatID_maj,0,10).arg(rk->subcatID_min,0,10).arg(rk->attrID,0,10).arg(cid_as);
    qDebug() << QString("cid full string: ") << cidstr;
    QString data;
    QString name = ui->nameField->text();
    QString brand = ui->brandField->text();
    QString size = ui->sizeBox->currentText();
    QString interface = ui->interfaceBox->currentText();
    QString formfac = ui->formfacBox->currentText();
    QString speed = ui->speedBox->text();
    QString comments = ui->commentsText->toPlainText();
    data = QString("INSERT INTO RAM (Name, Brand, Size, FormFactor, Interface, Speed, Comments, cid, cidstr) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9')").arg(name).arg(brand).arg(size).arg(formfac).arg(interface).arg(speed).arg(comments).arg(lastcid,0,10).arg(cidstr);
    return data;
}

RAMEntryDialog::~RAMEntryDialog()
{
    delete ui;
}
