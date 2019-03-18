#ifndef ADDPOPUP_H
#define ADDPOPUP_H

#include <QDialog>

namespace Ui {
class AddPopup;
}

class AddPopup : public QDialog
{
    Q_OBJECT

public:
    explicit AddPopup(QWidget *parent = 0);
    ~AddPopup();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddPopup *ui;
};

#endif // ADDPOPUP_H
