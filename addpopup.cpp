#include "addpopup.h"
#include "ui_addpopup.h"

AddPopup::AddPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPopup)
{
    if(Add == true)
        ui->pushButton->setText("Add");
    if(Edit == true)
        ui->pushButton->setText("Save");
    ui->setupUi(this);
}

AddPopup::~AddPopup()
{
    delete ui;
}

void AddPopup::on_pushButton_clicked()
{
    if(Add == true)
    {
        int Year = ui->lineEdit_3->text().toInt();
        ToBeAdded = new Book(ui->lineEdit->text(), ui->lineEdit_2->text(), Year, 0);
        if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == "")
        {
            ErrorPopup Error;
            Error.setModal(true);
            Error.exec();
            Confirm = false;
            AddPopup::close();
            return;
        }
        Confirm = true;
    AddPopup::close();
    }
    if(Edit == true)
    {
        int Year = ui->lineEdit_3->text().toInt();
        ToBeAdded = new Book(ui->lineEdit->text(), ui->lineEdit_2->text(), Year, 0);
        if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == "")
        {
            ErrorPopup Error;
            Error.setModal(true);
            Error.exec();
            Confirm = false;
            AddPopup::close();
            return;
        }
        Confirm = true;
        AddPopup::close();
    }
}

void AddPopup::on_pushButton_2_clicked()
{
    AddPopup::close();
}

void AddPopup::setAuthor()
{
    ui->lineEdit->setText(Author);
}

void AddPopup::setTitle()
{
    ui->lineEdit_2->setText(Title);
}

void AddPopup::setYear()
{
    QString StringYear = QString::number(Year);
    ui->lineEdit_3->setText(StringYear);
}

void AddPopup::SwapButton(QString NewText)
{
    ui->pushButton->setText(NewText);
}

void AddPopup::SetValidator()
{
    QValidator *Valid = new QIntValidator(-2500, 2500, this);
    ui->lineEdit_3->setValidator(Valid);
}

