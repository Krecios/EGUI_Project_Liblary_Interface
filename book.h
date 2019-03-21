#ifndef BOOK_H
#define BOOK_H

class Book{
private:
    QString Author;
    QString Title;
    QString Year;
public:
    Book()
    {
    }

    Book(QString NA, QString NT, QString NY)
    {
        Author = NA;
        Title = NT;
        Year = NY;
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

    QString getYear()
    {
        return Year;
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
            while(!in.atEnd())
            {
                QString fileLine = in.readLine();
                QStringList lineToken = fileLine.split(";",QString::SkipEmptyParts);
                Book *newBook = new Book(lineToken.at(0),lineToken.at(1),lineToken.at(2));
                Lib.append(newBook);
            }
        }
        file.close();
    }

    void SaveToFile()
    {
        QFile file("BooksDatabase.csv");
        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream in(&file);
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
        }

    }

    int columnCount(const QModelIndex &parent) const
    {
        return 3;
    }

    int rowCount(const QModelIndex &parent) const
    {
        return Lib.count();
    }


};

#endif // BOOK_H
