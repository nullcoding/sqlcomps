#include "newentrydialog.h"
#include "ui_newentrydialog.h"
#include "id_class_lists.cpp"

NewEntryDialog::NewEntryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEntryDialog)
{
    ui->setupUi(this);
    setupLists();
    hk = new HDD_keys();
}

void NewEntryDialog::setupLists()
{
    QStringList sizes;
    QStringList interfaces;
    QStringList formfactors;

    sizes << "32" << "40" << "48" << "64" << "73" << "80" << "100" << "120" << "128" << "160" << "200" << "240" << "256" << "320" << "360" << "480" << "500" << "512" << "640" << "750" << "900" << "1000" << "1024" << "1536" << "2048" << "2560" << "3072" << "4096";
    interfaces << "PATA" << "SATA1" << "SATA2" << "SATA3" << "mSATA" << "SCSI" << "SAS" << "OTHER";
    formfactors << "1.8" << "2.5" << "3.5";

    ui->sizeBox->addItems(sizes);
    ui->interfaceBox->addItems(interfaces);
    ui->formfacBox->addItems(formfactors);
}

void NewEntryDialog::generateMajorKey()
{

}

void NewEntryDialog::generateMinorKey()
{

}

QString NewEntryDialog::generateUID()
{
    return QString("fuck");
}

QString NewEntryDialog::returnData()
{
    hk->getMajSubCatID(ui->formfacBox->currentIndex());
    hk->getMinSubCatID(ui->interfaceBox->currentIndex());
    int lastcid = hk->getLast_cid();
    QString cid_as = QString("%1").arg(lastcid, 4, 10, QChar('0')).toUpper();
    //qDebug() << QString("cid as string: ") << cid_as;
    QString cidstr = QString("%1%2%3%4-%5").arg(hk->catID).arg(hk->subcatID_maj,0,10).arg(hk->subcatID_min,0,10).arg(hk->attrID,0,10).arg(cid_as);
    //qDebug() << cidstr;
    QString data;
    QString name = ui->nameField->text();
    QString brand = ui->brandField->text();
    QString size = ui->sizeBox->currentText();
    QString interface = ui->interfaceBox->currentText();
    QString formfac = ui->formfacBox->currentText();
    QString serial = ui->serialBox->text();
    QString comments = ui->commentsText->toPlainText();
    //data = QString("INSERT INTO HDD (Name, Brand, Size, Interface, FormFactor, Serial, Comments, uid, cid, cidstr) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10')").arg(name).arg(brand).arg(size).arg(interface).arg(formfac).arg(serial).arg(comments).arg(135,0,10).arg(lastcid,0,10).arg(cidstr);
    data = QString("INSERT INTO HDD (Name, Brand, Size, Interface, FormFactor, Serial, Comments, cid, cidstr) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9')").arg(name).arg(brand).arg(size).arg(interface).arg(formfac).arg(serial).arg(comments).arg(lastcid,0,10).arg(cidstr);
    return data;
}

NewEntryDialog::~NewEntryDialog()
{
    delete ui;
}
