#ifndef EDITPOPUP_H
#define EDITPOPUP_H

#include <QDialog>

namespace Ui {
class EditPopup;
}

class EditPopup : public QDialog
{
    Q_OBJECT

public:
    explicit EditPopup(QWidget *parent = 0);
    ~EditPopup();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditPopup *ui;
};

#endif // EDITPOPUP_H
