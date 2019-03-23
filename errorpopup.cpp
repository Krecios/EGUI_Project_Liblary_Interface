#include "errorpopup.h"
#include "ui_errorpopup.h"

ErrorPopup::ErrorPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorPopup)
{
    ui->setupUi(this);
}

ErrorPopup::~ErrorPopup()
{
    delete ui;
}

void ErrorPopup::on_pushButton_clicked()
{
    ErrorPopup::close();
}
