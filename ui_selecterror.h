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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SelectError
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *SelectError)
    {
        if (SelectError->objectName().isEmpty())
            SelectError->setObjectName(QStringLiteral("SelectError"));
        SelectError->resize(400, 129);
        verticalLayout_2 = new QVBoxLayout(SelectError);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SelectError);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(SelectError);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


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
