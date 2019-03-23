#ifndef ADDPOPUP_H
#define ADDPOPUP_H

#include <QDialog>
#include "mainwindow.h"
#include "book.h"
#include "errorpopup.h"

namespace Ui {
class AddPopup;
}

class AddPopup : public QDialog
{
    Q_OBJECT

public:
    explicit AddPopup(QWidget *parent = 0);
    ~AddPopup();
    Book *GetData()
    {
        return ToBeAdded;
    }
    bool Confirm = false;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddPopup *ui;
    Book* ToBeAdded;
};

#endif // ADDPOPUP_H
