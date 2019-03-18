#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QTextStream>
#include <QStandardItemModel>
#include <QFile>
#include <QString>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

    void startup();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void filter();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QComboBox *clr;
    bool FirstStartup = true;
};

#endif // MAINWINDOW_H
