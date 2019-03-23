/********************************************************************************
** Form generated from reading UI file 'errorpopup.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORPOPUP_H
#define UI_ERRORPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ErrorPopup
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *ErrorPopup)
    {
        if (ErrorPopup->objectName().isEmpty())
            ErrorPopup->setObjectName(QStringLiteral("ErrorPopup"));
        ErrorPopup->resize(400, 103);
        label = new QLabel(ErrorPopup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 331, 51));
        pushButton = new QPushButton(ErrorPopup);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 60, 141, 31));

        retranslateUi(ErrorPopup);

        QMetaObject::connectSlotsByName(ErrorPopup);
    } // setupUi

    void retranslateUi(QDialog *ErrorPopup)
    {
        ErrorPopup->setWindowTitle(QApplication::translate("ErrorPopup", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ErrorPopup", "ERROR : All the available fileds must be filled to add or edit a book", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ErrorPopup", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ErrorPopup: public Ui_ErrorPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORPOPUP_H
