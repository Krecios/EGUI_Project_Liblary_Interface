#include "deletedialog.h"
#include "ui_deletedialog.h"

DeleteDialog::DeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}

void DeleteDialog::on_pushButton_clicked()
{
    DeleteDialog::close();
}

void DeleteDialog::on_pushButton_2_clicked()
{
    DeleteDialog::close();
}
