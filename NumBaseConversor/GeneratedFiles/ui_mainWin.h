/********************************************************************************
** Form generated from reading UI file 'mainWin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWinClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *lineEditInput;
    QComboBox *comboBox;
    QLabel *label0;
    QLabel *label1;
    QLabel *label2;
    QLineEdit *lineEditHex;
    QLineEdit *lineEditDec;
    QLineEdit *lineEditOct;
    QLineEdit *lineEditBin;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QToolBar *toolBar;

    void setupUi(QMainWindow *mainWinClass)
    {
        if (mainWinClass->objectName().isEmpty())
            mainWinClass->setObjectName(QStringLiteral("mainWinClass"));
        mainWinClass->resize(740, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainWinClass->sizePolicy().hasHeightForWidth());
        mainWinClass->setSizePolicy(sizePolicy);
        mainWinClass->setMinimumSize(QSize(740, 400));
        mainWinClass->setMaximumSize(QSize(740, 400));
        centralWidget = new QWidget(mainWinClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(630, 80, 81, 28));
        lineEditInput = new QLineEdit(centralWidget);
        lineEditInput->setObjectName(QStringLiteral("lineEditInput"));
        lineEditInput->setGeometry(QRect(120, 80, 481, 31));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(14);
        lineEditInput->setFont(font);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(210, 20, 81, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(16);
        comboBox->setFont(font1);
        label0 = new QLabel(centralWidget);
        label0->setObjectName(QStringLiteral("label0"));
        label0->setGeometry(QRect(30, 20, 171, 31));
        label0->setFont(font1);
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(30, 80, 81, 31));
        label1->setFont(font);
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(30, 140, 61, 31));
        label2->setFont(font);
        lineEditHex = new QLineEdit(centralWidget);
        lineEditHex->setObjectName(QStringLiteral("lineEditHex"));
        lineEditHex->setGeometry(QRect(120, 140, 481, 31));
        lineEditHex->setFont(font);
        lineEditDec = new QLineEdit(centralWidget);
        lineEditDec->setObjectName(QStringLiteral("lineEditDec"));
        lineEditDec->setGeometry(QRect(120, 200, 481, 31));
        lineEditDec->setFont(font);
        lineEditOct = new QLineEdit(centralWidget);
        lineEditOct->setObjectName(QStringLiteral("lineEditOct"));
        lineEditOct->setGeometry(QRect(120, 260, 481, 31));
        lineEditOct->setFont(font);
        lineEditBin = new QLineEdit(centralWidget);
        lineEditBin->setObjectName(QStringLiteral("lineEditBin"));
        lineEditBin->setGeometry(QRect(120, 320, 561, 31));
        lineEditBin->setFont(font);
        label3 = new QLabel(centralWidget);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(30, 200, 61, 31));
        label3->setFont(font);
        label4 = new QLabel(centralWidget);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setGeometry(QRect(30, 260, 61, 31));
        label4->setFont(font);
        label5 = new QLabel(centralWidget);
        label5->setObjectName(QStringLiteral("label5"));
        label5->setGeometry(QRect(30, 320, 61, 31));
        label5->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 20, 191, 31));
        label->setFont(font1);
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(500, 20, 87, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(680, 360, 61, 21));
        mainWinClass->setCentralWidget(centralWidget);
        toolBar = new QToolBar(mainWinClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        mainWinClass->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(mainWinClass);

        QMetaObject::connectSlotsByName(mainWinClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainWinClass)
    {
        mainWinClass->setWindowTitle(QApplication::translate("mainWinClass", "NumBaseConversor", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mainWinClass", "Converse", Q_NULLPTR));
        lineEditInput->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("mainWinClass", "Hex", Q_NULLPTR)
         << QApplication::translate("mainWinClass", "Dec", Q_NULLPTR)
         << QApplication::translate("mainWinClass", "Oct", Q_NULLPTR)
         << QApplication::translate("mainWinClass", "Bin", Q_NULLPTR)
        );
        label0->setText(QApplication::translate("mainWinClass", "Input Type:", Q_NULLPTR));
        label1->setText(QApplication::translate("mainWinClass", "Input:", Q_NULLPTR));
        label2->setText(QApplication::translate("mainWinClass", "Hex:", Q_NULLPTR));
        lineEditHex->setText(QString());
        lineEditDec->setText(QString());
        lineEditOct->setText(QString());
        lineEditBin->setText(QString());
        label3->setText(QApplication::translate("mainWinClass", "Dec:", Q_NULLPTR));
        label4->setText(QApplication::translate("mainWinClass", "Oct:", Q_NULLPTR));
        label5->setText(QApplication::translate("mainWinClass", "Bin:", Q_NULLPTR));
        label->setText(QApplication::translate("mainWinClass", "OutPut Mode:", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("mainWinClass", "64", Q_NULLPTR)
         << QApplication::translate("mainWinClass", "48", Q_NULLPTR)
         << QApplication::translate("mainWinClass", "32", Q_NULLPTR)
         << QApplication::translate("mainWinClass", "24", Q_NULLPTR)
         << QApplication::translate("mainWinClass", "16", Q_NULLPTR)
         << QApplication::translate("mainWinClass", "8", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("mainWinClass", "Yusnows", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("mainWinClass", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainWinClass: public Ui_mainWinClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
