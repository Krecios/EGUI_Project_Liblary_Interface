#ifndef BOOK_H
#define BOOK_H

class Book{
private:
    int index;
    QString Author;
    QString Title;
    int Year;
public:
    Book()
    {
    }

    Book(QString NA, QString NT, int NY, int NI)
    {
        Author = NA;
        Title = NT;
        Year = NY;
        index = NI;
    }

    ~Book()
    {
    }

    QString getAuthor()
    {
        return Author;
    }

    QString getTitle()
    {
        return Title;
    }

    int getYear()
    {
        return Year;
    }

    int getIndex()
    {
        return index;
    }

    void ModifyAuthor(QString NewAuthor)
    {
        Author = NewAuthor;
    }

    void ModifyTitle(QString NewTitle)
    {
        Title = NewTitle;
    }

    void ModifyYear(int NewYear)
    {
        Year = NewYear;
    }

    void ModifyIndex(int NewIndex)
    {
        index = NewIndex;
    }
};

class Liblary : public QAbstractTableModel
{
private:
    QList<Book*> Lib;
public:
    QList<Book*> GetLib()
    {
        return Lib;
    }

    void ModifyLib(QList<Book*> NewLib)
    {
        Lib = NewLib;
    }

    void removeBook(int index)
    {
        for(int i = 0; i<Lib.count(); i++)
        {
            if(Lib[i]->getIndex() == index)
            {
                Lib.removeOne(Lib[i]);
            }
        }
    }

    QString AuthorFromIndex(int index)
    {
        for(int i = 0; i<Lib.count(); i++)
        {
            if(Lib[i]->getIndex() == index)
            {
                return Lib[i]->getAuthor();
            }
        }
    }

    QString TitleFromIndex(int index)
    {
        for(int i = 0; i<Lib.count(); i++)
        {
            if(Lib[i]->getIndex() == index)
            {
                return Lib[i]->getTitle();
            }
        }
    }

    int YearFromIndex(int index)
    {
        for(int i = 0; i<Lib.count(); i++)
        {
            if(Lib[i]->getIndex() == index)
            {
                return Lib[i]->getYear();
            }
        }
    }

    void ModifyOnIndex(int index, QString NewAuthor, QString NewTitle, int NewYear)
    {
        for(int i = 0; i<Lib.count(); i++)
        {
            if(Lib[i]->getIndex() == index)
            {
                Book *Modify = Lib[i];
                Modify->ModifyAuthor(NewAuthor);
                Modify->ModifyTitle(NewTitle);
                Modify->ModifyYear(NewYear);
                removeBook(index);
                addBook(Modify);
            }
        }
    }

    void addBook(Book *newBook)
    {
        Lib.append(newBook);
    }
    void LoadFromFile()
    {
        QFile file("BooksDatabase.csv");
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file);
            int RowCount = 0;
            while(!in.atEnd())
            {
                QString fileLine = in.readLine();
                QStringList lineToken = fileLine.split(";",QString::SkipEmptyParts);
                QString YearGet = lineToken.at(2);
                int Year = YearGet.toInt();
                Book *newBook = new Book(lineToken.at(0),lineToken.at(1),Year, RowCount);
                Lib.append(newBook);
                RowCount++;
            }
        }
        file.close();
    }

    void SaveToFile()
    {
        QFile file("BooksDatabase.csv");
        file.remove();
        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&file);
            for(int i=0; i<Lib.count(); i++)
                {
                    stream << Lib[i]->getAuthor() << ";" << Lib[i]->getTitle() << ";" << Lib[i]->getYear() << endl;
                }
            file.close();
        }
    }

    QVariant data(const QModelIndex &index, int role) const
    {
        if(role != Qt::DisplayRole)
        {
            return QVariant();
        }
        else
        {
            if(index.column() == 0)
                return Lib[index.row()]->getAuthor();
            if(index.column() == 1)
                return Lib[index.row()]->getTitle();
            if(index.column() == 2)
                return Lib[index.row()]->getYear();
            if(index.column() == 3)
                return Lib[index.row()]->getIndex();
        }

    }

    int columnCount(const QModelIndex &parent) const
    {
        return 4;
    }

    int rowCount(const QModelIndex &parent) const
    {
        return Lib.count();
    }

    QVariant headerData(int section,Qt::Orientation,int role) const
    {
        if(role != Qt::DisplayRole)
        {
            return QVariant();
        }
        if(role == Qt::DisplayRole)
        {
            if(section == 0)
                return tr("Author");
            if(section == 1)
                return tr("Title");
            if(section == 2)
                return tr("Year");
        }
    }

    void SwapContent(int index, Book* Swap)
    {
        for(int i=0; i<Lib.count(); i++)
        {
            if(i == index)
            {
                Lib[i] = Swap;
            }
        }
    }
    int Size()
    {
        return Lib.count();
    }
};

#endif // BOOK_H
