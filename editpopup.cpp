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
    ToBeEdited = new Book(ui->textEdit->toPlainText(), ui->textEdit_2->toPlainText(), ui->textEdit_3->toPlainText(), 0);
    Confirm = true;
    EditPopup::close();
}

void EditPopup::on_pushButton_2_clicked()
{
    EditPopup::close();
}

void EditPopup::setAuthor()
{
    ui->textEdit->setText(Author);
}

void EditPopup::setTitle()
{
    ui->textEdit_2->setText(Title);
}

void EditPopup::setYear()
{
    ui->textEdit_3->setText(Year);
}
