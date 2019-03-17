#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QTextStream>
#include <QStandardItemModel>
#include <QFile>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel;
    QStringList year;

    clr=ui->comboBox;

    QFile file("BooksDatabase.csv");
    if (file.open(QIODevice::ReadOnly))
    {
        int lineindex = 0;
        QTextStream in(&file);

        while(!in.atEnd())
        {
            QString fileLine = in.readLine();
            QStringList lineToken = fileLine.split(";",QString::SkipEmptyParts);
            for (int j=0; j<lineToken.size();j++)
            {
                QString value = lineToken.at(j);
                if (j == 2)
                {
                    year<<lineToken.at(j);
                }
                QStandardItem *item = new QStandardItem(value);
                model->setItem(lineindex, j, item);
            }
            lineindex++;
        }
        file.close();

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Author"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Year"));
    }
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


    year.sort();
    year.removeDuplicates();
    ui->comboBox->addItems(year);
    ui->comboBox->setCurrentIndex(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    clr->setCurrentIndex(-1);
}
