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
    AddPopup::close();
}

void AddPopup::on_pushButton_2_clicked()
{
    AddPopup::close();
}
