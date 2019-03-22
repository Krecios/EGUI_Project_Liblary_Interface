#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addpopup.h"
#include "editpopup.h"
#include "deletedialog.h"
#include "book.h"
#include "addpopup.h"
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
    Lib = new Liblary;
    Lib->LoadFromFile();
    Lib->setHeaderData(0, Qt::Horizontal, QObject::tr("Author"));
    Lib->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    Lib->setHeaderData(2, Qt::Horizontal, QObject::tr("Year"));

    ui->tableView->setModel(Lib);
    //ui->tableView->hideColumn(3);
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
    ShowAll(Lib);
    start();
}

void MainWindow::on_pushButton_clicked()
{
    Book *Added;
    AddPopup addDialog;
    addDialog.Confirm = false;
    addDialog.setModal(true);
    addDialog.exec();
    if(addDialog.Confirm == true)
    {
        Added = addDialog.GetData();
        Lib->addBook(Added);
        Lib->SaveToFile();
        start();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    Book *Edit;
    EditPopup editDialog;
    int Row = ui->tableView->selectionModel()->currentIndex().row();
    QString EAuthor = Lib->AuthorFromIndex(Row);
    QString ETitle = Lib->TitleFromIndex(Row);
    QString EYear = Lib->YearFromIndex(Row);
    editDialog.Author = EAuthor;
    editDialog.Title = ETitle;
    editDialog.Year = EYear;
    editDialog.setAuthor();
    editDialog.setTitle();
    editDialog.setYear();
    editDialog.setModal(true);
    editDialog.exec();
    if(editDialog.Confirm == true)
    {
       int Row = ui->tableView->selectionModel()->currentIndex().row();
       Edit = editDialog.GetData();
       Edit->ModifyIndex(Row);
       Lib->removeBook(Row);
       Lib->SwapContent(Row, Edit);
       Lib->SaveToFile();
    }
    start();
}

void MainWindow::on_pushButton_3_clicked()
{
    DeleteDialog delDialog;
    delDialog.Confirm = false;
    delDialog.setModal(true);
    delDialog.exec();
    if(delDialog.Confirm == true)
    {
        int Row = ui->tableView->selectionModel()->currentIndex().row();
        Lib->removeBook(Row);
        Lib->SaveToFile();
    }
    start();
}

void MainWindow::filter()
{
    QString AuthorFilter;
    QString TitleFilter;
    QString YearFilter;
    int CurrentDisplayRow = 0;
    int CaseID = 0;
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
        int RowCount = 0;
        while(!in.atEnd())
        {
            QString fileLine = in.readLine();
            QStringList lineToken = fileLine.split(";",QString::SkipEmptyParts);
            switch(CaseID)
            {
                case 1:
                {
                    if (lineToken.at(0) != AuthorFilter)
                    {
                        ui->tableView->hideRow(RowCount);
                    }
                    lineindex++;
                break;
                }
                case 2:
                {
                    if (lineToken.at(1) != TitleFilter)
                    {
                        ui->tableView->hideRow(RowCount);
                    }
                    lineindex++;
                break;
                }
                case 3:
                {
                    if (lineToken.at(2) != YearFilter)
                    {
                        ui->tableView->hideRow(RowCount);
                    }
                    lineindex++;
                break;
                }
                case 4:
                {
                    if (lineToken.at(0) != AuthorFilter || lineToken.at(1) != TitleFilter)
                    {
                        ui->tableView->hideRow(RowCount);
                    }
                    lineindex++;
                break;
                }
                case 5:
                {
                    if (lineToken.at(0) != AuthorFilter || lineToken.at(2) != YearFilter)
                    {
                        ui->tableView->hideRow(RowCount);
                    }
                    lineindex++;
                break;
                }
                case 6:
                {
                    if (lineToken.at(1) != TitleFilter || lineToken.at(2) != YearFilter)
                    {
                        ui->tableView->hideRow(RowCount);
                    }
                    lineindex++;
                break;
                }
                case 7:
                {
                    if (lineToken.at(0) != AuthorFilter || lineToken.at(1) != TitleFilter || lineToken.at(2) != YearFilter)
                    {
                        ui->tableView->hideRow(RowCount);
                    }
                    lineindex++;
                break;
                }
            }
            RowCount++;
        }
        file.close();
    }

    Lib->setHeaderData(0, Qt::Horizontal, QObject::tr("Author"));
    Lib->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    Lib->setHeaderData(2, Qt::Horizontal, QObject::tr("Year"));

    if(CaseID != 0)
    {
        ui->tableView->setModel(Lib);
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

void MainWindow::ShowAll(Liblary *Show)
{
    for(int i=0; i<Show->Size(); i++)
    {
        ui->tableView->showRow(i);
    }
}
