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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditPopup
{
public:
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *EditPopup)
    {
        if (EditPopup->objectName().isEmpty())
            EditPopup->setObjectName(QStringLiteral("EditPopup"));
        EditPopup->resize(480, 249);
        label_2 = new QLabel(EditPopup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 80, 47, 13));
        pushButton = new QPushButton(EditPopup);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 180, 171, 41));
        pushButton_2 = new QPushButton(EditPopup);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 180, 171, 41));
        label = new QLabel(EditPopup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 30, 47, 13));
        label_3 = new QLabel(EditPopup);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 120, 47, 20));
        lineEdit = new QLineEdit(EditPopup);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 20, 321, 31));
        lineEdit_2 = new QLineEdit(EditPopup);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 70, 321, 31));
        lineEdit_3 = new QLineEdit(EditPopup);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 120, 321, 31));

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
