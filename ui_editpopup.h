/********************************************************************************
** Form generated from reading UI file 'editpopup.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPOPUP_H
#define UI_EDITPOPUP_H

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

class Ui_EditPopup
{
public:
    QTextEdit *textEdit_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QTextEdit *textEdit_3;
    QLabel *label_3;
    QTextEdit *textEdit;

    void setupUi(QDialog *EditPopup)
    {
        if (EditPopup->objectName().isEmpty())
            EditPopup->setObjectName(QStringLiteral("EditPopup"));
        EditPopup->resize(480, 249);
        textEdit_2 = new QTextEdit(EditPopup);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(140, 80, 311, 31));
        label_2 = new QLabel(EditPopup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 90, 47, 13));
        pushButton = new QPushButton(EditPopup);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 180, 171, 41));
        pushButton_2 = new QPushButton(EditPopup);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 180, 171, 41));
        label = new QLabel(EditPopup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 47, 13));
        textEdit_3 = new QTextEdit(EditPopup);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(140, 130, 311, 31));
        label_3 = new QLabel(EditPopup);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 130, 47, 20));
        textEdit = new QTextEdit(EditPopup);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(140, 30, 311, 31));

        retranslateUi(EditPopup);

        QMetaObject::connectSlotsByName(EditPopup);
    } // setupUi

    void retranslateUi(QDialog *EditPopup)
    {
        EditPopup->setWindowTitle(QApplication::translate("EditPopup", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("EditPopup", "Title:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("EditPopup", "Save", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("EditPopup", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("EditPopup", "Author:", Q_NULLPTR));
        label_3->setText(QApplication::translate("EditPopup", "Year:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditPopup: public Ui_EditPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPOPUP_H
