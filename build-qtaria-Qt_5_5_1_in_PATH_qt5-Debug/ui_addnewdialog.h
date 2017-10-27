/********************************************************************************
** Form generated from reading UI file 'addnewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWDIALOG_H
#define UI_ADDNEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addNewDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *addNewDialog)
    {
        if (addNewDialog->objectName().isEmpty())
            addNewDialog->setObjectName(QStringLiteral("addNewDialog"));
        addNewDialog->resize(538, 227);
        layoutWidget = new QWidget(addNewDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 391, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        okBtn = new QPushButton(addNewDialog);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(430, 80, 81, 26));
        cancelBtn = new QPushButton(addNewDialog);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(430, 160, 81, 26));

        retranslateUi(addNewDialog);

        QMetaObject::connectSlotsByName(addNewDialog);
    } // setupUi

    void retranslateUi(QDialog *addNewDialog)
    {
        addNewDialog->setWindowTitle(QApplication::translate("addNewDialog", "Dialog", 0));
        label->setText(QApplication::translate("addNewDialog", "URL:", 0));
        label_2->setText(QApplication::translate("addNewDialog", "Save to:", 0));
        okBtn->setText(QApplication::translate("addNewDialog", "OK", 0));
        cancelBtn->setText(QApplication::translate("addNewDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class addNewDialog: public Ui_addNewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWDIALOG_H
