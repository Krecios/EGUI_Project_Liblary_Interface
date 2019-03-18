#include "editpopup.h"
#include "ui_editpopup.h"

EditPopup::EditPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPopup)
{
    ui->setupUi(this);
}

EditPopup::~EditPopup()
{
    delete ui;
}

void EditPopup::on_pushButton_clicked()
{
    EditPopup::close();
}

void EditPopup::on_pushButton_2_clicked()
{
    EditPopup::close();
}
