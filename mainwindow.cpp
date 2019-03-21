#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addpopup.h"
#include "editpopup.h"
#include "deletedialog.h"
#include "book.h"
#include <QTableView>
#include <QTextStream>
#include <QStandardItemModel>
#include <QFile>
#include <QString>
#include <QList>
#include <QVariant>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clr=ui->comboBox;
    yearCombo();
    start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    Liblary *Lib = new Liblary;
    Lib->LoadFromFile();
    Lib->setHeaderData(0, Qt::Horizontal, QObject::tr("Author"));
    Lib->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    Lib->setHeaderData(2, Qt::Horizontal, QObject::tr("Year"));

    ui->tableView->setModel(Lib);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::yearCombo()
{
    QStringList year;
    QFile file("BooksDatabase.csv");
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);

        while(!in.atEnd())
        {
            QString fileLine = in.readLine();
            QStringList lineToken = fileLine.split(";",QString::SkipEmptyParts);
            for (int j=0; j<lineToken.size();j++)
            {
                if (j == 2)
                {
                    year<<lineToken.at(j);
                }
            }
        }
        file.close();

    }

    if(FirstStartup == true)
    {
        year.sort();
        year.removeDuplicates();
        ui->comboBox->addItems(year);
        ui->comboBox->setCurrentIndex(-1);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    clr->setCurrentIndex(-1);
    FirstStartup = false;
    start();
}

void MainWindow::on_pushButton_clicked()
{
    AddPopup addDialog;
    addDialog.setModal(true);
    addDialog.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    EditPopup editDialog;
    editDialog.setModal(true);
    editDialog.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    DeleteDialog delDialog;
    delDialog.setModal(true);
    delDialog.exec();
}

void MainWindow::filter()
{
    QString AuthorFilter;
    QString TitleFilter;
    QString YearFilter;
    int CurrentDisplayRow = 0;
    int CaseID = 0;
    QStandardItemModel *FilteredData = new QStandardItemModel;
    QFile file("BooksDatabase.csv");

    AuthorFilter = ui->textEdit_2->toPlainText();
    TitleFilter = ui->textEdit->toPlainText();
    YearFilter = ui->comboBox->currentText();

    if(AuthorFilter != "") CaseID=1;
    if(TitleFilter != "") CaseID=2;
    if(YearFilter != "") CaseID=3;
    if(AuthorFilter != "" && TitleFilter != "") CaseID=4;
    if(AuthorFilter != "" && YearFilter != "") CaseID=5;
    if(YearFilter != "" && TitleFilter != "") CaseID=6;
    if(AuthorFilter != "" && TitleFilter != "" && YearFilter != "") CaseID=7;

    if(file.open(QIODevice::ReadOnly))
    {
        int lineindex = 0;
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString fileLine = in.readLine();
            QStringList lineToken = fileLine.split(";",QString::SkipEmptyParts);
            switch(CaseID)
            {
                case 1:
                {
                    if (lineToken.at(0) == AuthorFilter)
                    {
                        for (int j=0; j<lineToken.size(); j++)
                        {
                            QString value = lineToken.at(j);
                            QStandardItem *item = new QStandardItem(value);
                            FilteredData->setItem(CurrentDisplayRow, j, item);
                        }
                         CurrentDisplayRow++;
                }
                lineindex++;
                break;
                }
                case 2:
                {
                    if (lineToken.at(1) == TitleFilter)
                    {
                        for (int j=0; j<lineToken.size(); j++)
                        {
                            QString value = lineToken.at(j);
                            QStandardItem *item = new QStandardItem(value);
                            FilteredData->setItem(CurrentDisplayRow, j, item);
                        }
                         CurrentDisplayRow++;
                }
                lineindex++;
                break;
                }
                case 3:
                {
                    if (lineToken.at(2) == YearFilter)
                    {
                        for (int j=0; j<lineToken.size(); j++)
                        {
                            QString value = lineToken.at(j);
                            QStandardItem *item = new QStandardItem(value);
                            FilteredData->setItem(CurrentDisplayRow, j, item);
                        }
                         CurrentDisplayRow++;
                }
                lineindex++;
                break;
                }
                case 4:
                {
                    if (lineToken.at(0) == AuthorFilter && lineToken.at(1) == TitleFilter)
                    {
                        for (int j=0; j<lineToken.size(); j++)
                        {
                            QString value = lineToken.at(j);
                            QStandardItem *item = new QStandardItem(value);
                            FilteredData->setItem(CurrentDisplayRow, j, item);
                        }
                         CurrentDisplayRow++;
                }
                lineindex++;
                break;
                }
                case 5:
                {
                    if (lineToken.at(0) == AuthorFilter && lineToken.at(2) == YearFilter)
                    {
                        for (int j=0; j<lineToken.size(); j++)
                        {
                            QString value = lineToken.at(j);
                            QStandardItem *item = new QStandardItem(value);
                            FilteredData->setItem(CurrentDisplayRow, j, item);
                        }
                         CurrentDisplayRow++;
                }
                lineindex++;
                break;
                }
                case 6:
                {
                    if (lineToken.at(1) == TitleFilter && lineToken.at(2) == YearFilter)
                    {
                        for (int j=0; j<lineToken.size(); j++)
                        {
                            QString value = lineToken.at(j);
                            QStandardItem *item = new QStandardItem(value);
                            FilteredData->setItem(CurrentDisplayRow, j, item);
                        }
                         CurrentDisplayRow++;
                }
                lineindex++;
                break;
                }
                case 7:
                {
                    if (lineToken.at(0) == AuthorFilter && lineToken.at(1) == TitleFilter && lineToken.at(2) == YearFilter)
                    {
                        for (int j=0; j<lineToken.size(); j++)
                        {
                            QString value = lineToken.at(j);
                            QStandardItem *item = new QStandardItem(value);
                            FilteredData->setItem(CurrentDisplayRow, j, item);
                        }
                         CurrentDisplayRow++;
                }
                lineindex++;
                break;
                }
            }
        }
        file.close();
    }

    FilteredData->setHeaderData(0, Qt::Horizontal, QObject::tr("Author"));
    FilteredData->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    FilteredData->setHeaderData(2, Qt::Horizontal, QObject::tr("Year"));

    if(CaseID != 0)
    {
        ui->tableView->setModel(FilteredData);
        ui->tableView->verticalHeader()->hide();
        if(CurrentDisplayRow != 0)
        {
            ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
            ui->tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    filter();
}
