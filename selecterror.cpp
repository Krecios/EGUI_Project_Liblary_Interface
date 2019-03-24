#include "selecterror.h"
#include "ui_selecterror.h"

SelectError::SelectError(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectError)
{
    ui->setupUi(this);
}

SelectError::~SelectError()
{
    delete ui;
}

void SelectError::on_pushButton_clicked()
{
    SelectError::close();
}
