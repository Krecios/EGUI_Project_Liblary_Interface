#ifndef EDITPOPUP_H
#define EDITPOPUP_H

#include <QDialog>
#include "mainwindow.h"
#include "book.h"
#include "errorpopup.h"

namespace Ui {
class EditPopup;
}

class EditPopup : public QDialog
{
    Q_OBJECT

public:
    explicit EditPopup(QWidget *parent = 0);
    ~EditPopup();
    bool Confirm = false;
    QString Author;
    QString Title;
    QString Year;
    void setAuthor();
    void setTitle();
    void setYear();
    Book *GetData()
    {
        return ToBeEdited;
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditPopup *ui;
    Book *ToBeEdited;
};

#endif // EDITPOPUP_H
