/********************************************************************************
** Form generated from reading UI file 'selecterror.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTERROR_H
#define UI_SELECTERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SelectError
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *SelectError)
    {
        if (SelectError->objectName().isEmpty())
            SelectError->setObjectName(QStringLiteral("SelectError"));
        SelectError->resize(400, 129);
        label = new QLabel(SelectError);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 301, 51));
        pushButton = new QPushButton(SelectError);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 80, 141, 31));

        retranslateUi(SelectError);

        QMetaObject::connectSlotsByName(SelectError);
    } // setupUi

    void retranslateUi(QDialog *SelectError)
    {
        SelectError->setWindowTitle(QApplication::translate("SelectError", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("SelectError", "None of the books is selected. Please select a book.", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SelectError", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectError: public Ui_SelectError {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTERROR_H
