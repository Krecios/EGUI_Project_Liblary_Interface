#include "addpopup.h"
#include "ui_addpopup.h"

AddPopup::AddPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPopup)
{
    ui->setupUi(this);
}

AddPopup::~AddPopup()
{
    delete ui;
}

void AddPopup::on_pushButton_clicked()
{
    ToBeAdded = new Book(ui->textEdit->toPlainText(), ui->textEdit_2->toPlainText(), ui->textEdit_3->toPlainText());
    Confirm = true;
    AddPopup::close();
}

void AddPopup::on_pushButton_2_clicked()
{
    AddPopup::close();
}
