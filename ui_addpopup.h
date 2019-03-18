/********************************************************************************
** Form generated from reading UI file 'addpopup.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPOPUP_H
#define UI_ADDPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddPopup
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AddPopup)
    {
        if (AddPopup->objectName().isEmpty())
            AddPopup->setObjectName(QStringLiteral("AddPopup"));
        AddPopup->resize(497, 233);
        pushButton = new QPushButton(AddPopup);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 170, 171, 41));
        pushButton_2 = new QPushButton(AddPopup);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 170, 171, 41));
        textEdit = new QTextEdit(AddPopup);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(150, 20, 311, 31));
        textEdit_2 = new QTextEdit(AddPopup);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(150, 70, 311, 31));
        textEdit_3 = new QTextEdit(AddPopup);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(150, 120, 311, 31));
        label = new QLabel(AddPopup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 30, 47, 13));
        label_2 = new QLabel(AddPopup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 80, 47, 13));
        label_3 = new QLabel(AddPopup);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 120, 47, 20));

        retranslateUi(AddPopup);

        QMetaObject::connectSlotsByName(AddPopup);
    } // setupUi

    void retranslateUi(QDialog *AddPopup)
    {
        AddPopup->setWindowTitle(QApplication::translate("AddPopup", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AddPopup", "Add", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("AddPopup", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("AddPopup", "Author:", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddPopup", "Title:", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddPopup", "Year:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddPopup: public Ui_AddPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPOPUP_H
