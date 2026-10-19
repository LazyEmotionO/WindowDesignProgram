/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName("MyWidget");
        MyWidget->resize(876, 682);
        gridLayout_3 = new QGridLayout(MyWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        tableWidget = new QTableWidget(MyWidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(761, 321));

        gridLayout_3->addWidget(tableWidget, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(17, 185, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(MyWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(47, 16));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(MyWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(391, 21));

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        label_2 = new QLabel(MyWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(28, 16));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(MyWidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setMinimumSize(QSize(391, 21));

        gridLayout->addWidget(lineEdit_3, 1, 1, 1, 1);

        label_3 = new QLabel(MyWidget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(35, 16));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_4 = new QLineEdit(MyWidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setMinimumSize(QSize(391, 21));

        gridLayout->addWidget(lineEdit_4, 2, 1, 1, 1);

        label_4 = new QLabel(MyWidget);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(58, 16));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_5 = new QLineEdit(MyWidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setMinimumSize(QSize(391, 21));

        gridLayout->addWidget(lineEdit_5, 3, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer = new QSpacerItem(158, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(181, 31));

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(88, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(MyWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(201, 31));

        gridLayout_2->addWidget(pushButton_2, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(148, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 4, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 3, 0, 1, 1);

        tableWidget->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        lineEdit_4->raise();
        lineEdit_5->raise();
        pushButton->raise();
        pushButton_2->raise();

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
        label->setText(QCoreApplication::translate("MyWidget", "Number", nullptr));
        label_2->setText(QCoreApplication::translate("MyWidget", "Class", nullptr));
        label_3->setText(QCoreApplication::translate("MyWidget", "Name", nullptr));
        label_4->setText(QCoreApplication::translate("MyWidget", "TelePhone", nullptr));
        pushButton->setText(QCoreApplication::translate("MyWidget", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MyWidget", "Remit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
