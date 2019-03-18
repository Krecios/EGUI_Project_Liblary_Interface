/********************************************************************************
** Form generated from reading UI file 'deletedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEDIALOG_H
#define UI_DELETEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeleteDialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *DeleteDialog)
    {
        if (DeleteDialog->objectName().isEmpty())
            DeleteDialog->setObjectName(QStringLiteral("DeleteDialog"));
        DeleteDialog->resize(422, 87);
        pushButton = new QPushButton(DeleteDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 40, 191, 41));
        pushButton_2 = new QPushButton(DeleteDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 40, 191, 41));
        label = new QLabel(DeleteDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 10, 221, 16));

        retranslateUi(DeleteDialog);

        QMetaObject::connectSlotsByName(DeleteDialog);
    } // setupUi

    void retranslateUi(QDialog *DeleteDialog)
    {
        DeleteDialog->setWindowTitle(QApplication::translate("DeleteDialog", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DeleteDialog", "Yes", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("DeleteDialog", "No", Q_NULLPTR));
        label->setText(QApplication::translate("DeleteDialog", "Are you sure you want to delete this book?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeleteDialog: public Ui_DeleteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEDIALOG_H
