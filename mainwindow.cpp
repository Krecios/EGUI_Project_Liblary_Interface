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
    /*Liblary *Test = new Liblary;
    Book *t1 = new Book("a","b","c");
    Book *t2 = new Book("aa","bb","cc");
    Book *t3 = new Book("aaa","bbb","ccc");
    Test->addBook(t1);
    Test->addBook(t2);
    Test->addBook(t3);
    ui->tableView->setModel(Test);*/
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
    Liblary *Lib = new Liblary;
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
                        Book *newBook = new Book(lineToken.at(0),lineToken.at(1),lineToken.at(2));
                        Lib->addBook(newBook);
                    }
                    lineindex++;
                break;
                }
                case 2:
                {
                    if (lineToken.at(1) == TitleFilter)
                    {
                        Book *newBook = new Book(lineToken.at(0),lineToken.at(1),lineToken.at(2));
                        Lib->addBook(newBook);;
                    }
                    lineindex++;
                break;
                }
                case 3:
                {
                    if (lineToken.at(2) == YearFilter)
                    {
                        Book *newBook = new Book(lineToken.at(0),lineToken.at(1),lineToken.at(2));
                        Lib->addBook(newBook);
                    }
                    lineindex++;
                break;
                }
                case 4:
                {
                    if (lineToken.at(0) == AuthorFilter && lineToken.at(1) == TitleFilter)
                    {
                        Book *newBook = new Book(lineToken.at(0),lineToken.at(1),lineToken.at(2));
                        Lib->addBook(newBook);
                    }
                    lineindex++;
                break;
                }
                case 5:
                {
                    if (lineToken.at(0) == AuthorFilter && lineToken.at(2) == YearFilter)
                    {
                        Book *newBook = new Book(lineToken.at(0),lineToken.at(1),lineToken.at(2));
                        Lib->addBook(newBook);
                    }
                    lineindex++;
                break;
                }
                case 6:
                {
                    if (lineToken.at(1) == TitleFilter && lineToken.at(2) == YearFilter)
                    {
                        Book *newBook = new Book(lineToken.at(0),lineToken.at(1),lineToken.at(2));
                        Lib->addBook(newBook);
                    }
                    lineindex++;
                break;
                }
                case 7:
                {
                    if (lineToken.at(0) == AuthorFilter && lineToken.at(1) == TitleFilter && lineToken.at(2) == YearFilter)
                    {
                        Book *newBook = new Book(lineToken.at(0),lineToken.at(1),lineToken.at(2));
                        Lib->addBook(newBook);
                    }
                    lineindex++;
                break;
                }
            }
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
