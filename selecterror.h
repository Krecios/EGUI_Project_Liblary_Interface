#ifndef SELECTERROR_H
#define SELECTERROR_H

#include <QDialog>

namespace Ui {
class SelectError;
}

class SelectError : public QDialog
{
    Q_OBJECT

public:
    explicit SelectError(QWidget *parent = 0);
    ~SelectError();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SelectError *ui;
};

#endif // SELECTERROR_H
