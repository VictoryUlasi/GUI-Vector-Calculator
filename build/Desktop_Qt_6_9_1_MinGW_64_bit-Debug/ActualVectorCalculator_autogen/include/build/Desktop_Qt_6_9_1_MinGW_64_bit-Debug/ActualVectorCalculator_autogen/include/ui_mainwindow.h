/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *header;
    QPushButton *addBtn;
    QPushButton *subBtn;
    QPushButton *multBtn;
    QPushButton *dotBtn;
    QPushButton *crossBtn;
    QPushButton *angleBtn;
    QPushButton *magBtn;
    QPushButton *pltBtn;
    QTextEdit *resultantField;
    QCheckBox *checkBox3D;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *v21;
    QLineEdit *v22;
    QLineEdit *v23;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *v11;
    QLineEdit *v12;
    QLineEdit *v13;
    QCheckBox *scalarMultCheckBox;
    QCheckBox *magCheckBox;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        header = new QTextEdit(centralwidget);
        header->setObjectName("header");
        header->setEnabled(true);
        header->setGeometry(QRect(180, 0, 451, 61));
        header->setReadOnly(true);
        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName("addBtn");
        addBtn->setGeometry(QRect(170, 250, 151, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tahoma")});
        font.setBold(true);
        addBtn->setFont(font);
        addBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        subBtn = new QPushButton(centralwidget);
        subBtn->setObjectName("subBtn");
        subBtn->setGeometry(QRect(330, 250, 151, 61));
        subBtn->setFont(font);
        subBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        multBtn = new QPushButton(centralwidget);
        multBtn->setObjectName("multBtn");
        multBtn->setEnabled(false);
        multBtn->setGeometry(QRect(490, 250, 151, 61));
        multBtn->setFont(font);
        multBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        dotBtn = new QPushButton(centralwidget);
        dotBtn->setObjectName("dotBtn");
        dotBtn->setGeometry(QRect(170, 320, 151, 61));
        dotBtn->setFont(font);
        dotBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        crossBtn = new QPushButton(centralwidget);
        crossBtn->setObjectName("crossBtn");
        crossBtn->setEnabled(false);
        crossBtn->setGeometry(QRect(330, 320, 151, 61));
        crossBtn->setFont(font);
        crossBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        angleBtn = new QPushButton(centralwidget);
        angleBtn->setObjectName("angleBtn");
        angleBtn->setGeometry(QRect(490, 320, 151, 61));
        angleBtn->setFont(font);
        angleBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        magBtn = new QPushButton(centralwidget);
        magBtn->setObjectName("magBtn");
        magBtn->setEnabled(false);
        magBtn->setGeometry(QRect(170, 390, 151, 61));
        magBtn->setFont(font);
        magBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pltBtn = new QPushButton(centralwidget);
        pltBtn->setObjectName("pltBtn");
        pltBtn->setGeometry(QRect(490, 390, 151, 61));
        pltBtn->setFont(font);
        pltBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        resultantField = new QTextEdit(centralwidget);
        resultantField->setObjectName("resultantField");
        resultantField->setGeometry(QRect(10, 480, 781, 70));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tahoma")});
        font1.setPointSize(28);
        font1.setBold(true);
        resultantField->setFont(font1);
        resultantField->setReadOnly(true);
        checkBox3D = new QCheckBox(centralwidget);
        checkBox3D->setObjectName("checkBox3D");
        checkBox3D->setGeometry(QRect(660, 140, 51, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tahoma")});
        font2.setPointSize(11);
        font2.setBold(true);
        checkBox3D->setFont(font2);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(140, 60, 511, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        v21 = new QLineEdit(gridLayoutWidget);
        v21->setObjectName("v21");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Tahoma")});
        font3.setPointSize(20);
        font3.setBold(true);
        v21->setFont(font3);
        v21->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(v21);

        v22 = new QLineEdit(gridLayoutWidget);
        v22->setObjectName("v22");
        v22->setFont(font3);
        v22->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(v22);

        v23 = new QLineEdit(gridLayoutWidget);
        v23->setObjectName("v23");
        v23->setEnabled(false);
        v23->setFont(font3);
        v23->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(v23);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        v11 = new QLineEdit(gridLayoutWidget);
        v11->setObjectName("v11");
        v11->setFont(font3);
        v11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(v11);

        v12 = new QLineEdit(gridLayoutWidget);
        v12->setObjectName("v12");
        v12->setFont(font3);
        v12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(v12);

        v13 = new QLineEdit(gridLayoutWidget);
        v13->setObjectName("v13");
        v13->setEnabled(false);
        v13->setFont(font3);
        v13->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(v13);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        scalarMultCheckBox = new QCheckBox(centralwidget);
        scalarMultCheckBox->setObjectName("scalarMultCheckBox");
        scalarMultCheckBox->setGeometry(QRect(660, 160, 141, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Tahoma")});
        font4.setPointSize(8);
        font4.setBold(true);
        scalarMultCheckBox->setFont(font4);
        magCheckBox = new QCheckBox(centralwidget);
        magCheckBox->setObjectName("magCheckBox");
        magCheckBox->setGeometry(QRect(660, 180, 131, 21));
        magCheckBox->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        header->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:700;\">VECTOR CALCULATOR</span></p></body></html>", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "Vector Addition", nullptr));
        subBtn->setText(QCoreApplication::translate("MainWindow", "Vector Subtraction", nullptr));
        multBtn->setText(QCoreApplication::translate("MainWindow", "Vector Multiplication", nullptr));
        dotBtn->setText(QCoreApplication::translate("MainWindow", "Dot Product", nullptr));
        crossBtn->setText(QCoreApplication::translate("MainWindow", "Cross Product", nullptr));
        angleBtn->setText(QCoreApplication::translate("MainWindow", "Angle Between Vectors", nullptr));
        magBtn->setText(QCoreApplication::translate("MainWindow", "Magnitude", nullptr));
        pltBtn->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        resultantField->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Tahoma'; font-size:28pt; font-weight:700; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        checkBox3D->setText(QCoreApplication::translate("MainWindow", "3-D", nullptr));
        v21->setText(QString());
        v22->setText(QString());
        v23->setText(QString());
        v11->setText(QString());
        v12->setText(QString());
        v13->setText(QString());
        scalarMultCheckBox->setText(QCoreApplication::translate("MainWindow", "Vector Multiplication", nullptr));
        magCheckBox->setText(QCoreApplication::translate("MainWindow", "Magnitude", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
