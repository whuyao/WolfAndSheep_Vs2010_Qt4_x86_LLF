/********************************************************************************
** Form generated from reading UI file 'wolfandsheep_qtver.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WOLFANDSHEEP_QTVER_H
#define UI_WOLFANDSHEEP_QTVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_WolfAndSheep_qtverClass
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *gridview;
    QwtPlot *qwtPlot;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QPushButton *initializeB;
    QPushButton *startB;
    QPushButton *pauseB;
    QPushButton *endB;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *sheepnumSB;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *wolfnumSB;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QSlider *speedS;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *WolfAndSheep_qtverClass)
    {
        if (WolfAndSheep_qtverClass->objectName().isEmpty())
            WolfAndSheep_qtverClass->setObjectName(QString::fromUtf8("WolfAndSheep_qtverClass"));
        WolfAndSheep_qtverClass->resize(696, 528);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WolfAndSheep_qtverClass->sizePolicy().hasHeightForWidth());
        WolfAndSheep_qtverClass->setSizePolicy(sizePolicy);
        WolfAndSheep_qtverClass->setMinimumSize(QSize(696, 528));
        WolfAndSheep_qtverClass->setMaximumSize(QSize(696, 528));
        WolfAndSheep_qtverClass->setSizeGripEnabled(false);
        horizontalLayout_4 = new QHBoxLayout(WolfAndSheep_qtverClass);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridview = new QLabel(WolfAndSheep_qtverClass);
        gridview->setObjectName(QString::fromUtf8("gridview"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gridview->sizePolicy().hasHeightForWidth());
        gridview->setSizePolicy(sizePolicy1);
        gridview->setMinimumSize(QSize(546, 250));
        gridview->setMaximumSize(QSize(546, 250));

        verticalLayout_5->addWidget(gridview);

        qwtPlot = new QwtPlot(WolfAndSheep_qtverClass);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));
        sizePolicy1.setHeightForWidth(qwtPlot->sizePolicy().hasHeightForWidth());
        qwtPlot->setSizePolicy(sizePolicy1);
        qwtPlot->setMinimumSize(QSize(546, 250));
        qwtPlot->setMaximumSize(QSize(546, 250));

        verticalLayout_5->addWidget(qwtPlot);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(WolfAndSheep_qtverClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMaximumSize(QSize(118, 142));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        initializeB = new QPushButton(groupBox);
        initializeB->setObjectName(QString::fromUtf8("initializeB"));
        sizePolicy2.setHeightForWidth(initializeB->sizePolicy().hasHeightForWidth());
        initializeB->setSizePolicy(sizePolicy2);
        initializeB->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_3->addWidget(initializeB);

        startB = new QPushButton(groupBox);
        startB->setObjectName(QString::fromUtf8("startB"));
        sizePolicy2.setHeightForWidth(startB->sizePolicy().hasHeightForWidth());
        startB->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(startB);

        pauseB = new QPushButton(groupBox);
        pauseB->setObjectName(QString::fromUtf8("pauseB"));
        sizePolicy2.setHeightForWidth(pauseB->sizePolicy().hasHeightForWidth());
        pauseB->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(pauseB);

        endB = new QPushButton(groupBox);
        endB->setObjectName(QString::fromUtf8("endB"));
        sizePolicy2.setHeightForWidth(endB->sizePolicy().hasHeightForWidth());
        endB->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(endB);


        verticalLayout_4->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(WolfAndSheep_qtverClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMaximumSize(QSize(118, 127));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label);

        sheepnumSB = new QSpinBox(groupBox_2);
        sheepnumSB->setObjectName(QString::fromUtf8("sheepnumSB"));
        sizePolicy2.setHeightForWidth(sheepnumSB->sizePolicy().hasHeightForWidth());
        sheepnumSB->setSizePolicy(sizePolicy2);
        sheepnumSB->setMinimum(250);
        sheepnumSB->setMaximum(500);
        sheepnumSB->setValue(500);

        horizontalLayout->addWidget(sheepnumSB);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(label_2);

        wolfnumSB = new QSpinBox(groupBox_2);
        wolfnumSB->setObjectName(QString::fromUtf8("wolfnumSB"));
        sizePolicy2.setHeightForWidth(wolfnumSB->sizePolicy().hasHeightForWidth());
        wolfnumSB->setSizePolicy(sizePolicy2);
        wolfnumSB->setMinimum(50);
        wolfnumSB->setMaximum(300);
        wolfnumSB->setValue(50);

        horizontalLayout_2->addWidget(wolfnumSB);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        speedS = new QSlider(groupBox_2);
        speedS->setObjectName(QString::fromUtf8("speedS"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(speedS->sizePolicy().hasHeightForWidth());
        speedS->setSizePolicy(sizePolicy3);
        speedS->setMinimum(1);
        speedS->setMaximum(100);
        speedS->setValue(50);
        speedS->setOrientation(Qt::Horizontal);
        speedS->setTickPosition(QSlider::TicksAbove);

        verticalLayout->addWidget(speedS);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_4->addWidget(groupBox_2);


        verticalLayout_6->addLayout(verticalLayout_4);

        textEdit = new QTextEdit(WolfAndSheep_qtverClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(120, 127));
        textEdit->setMaximumSize(QSize(120, 127));
        textEdit->setStyleSheet(QString::fromUtf8(""));
        textEdit->setReadOnly(true);

        verticalLayout_6->addWidget(textEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_6);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(WolfAndSheep_qtverClass);

        QMetaObject::connectSlotsByName(WolfAndSheep_qtverClass);
    } // setupUi

    void retranslateUi(QDialog *WolfAndSheep_qtverClass)
    {
        WolfAndSheep_qtverClass->setWindowTitle(QApplication::translate("WolfAndSheep_qtverClass", "WolfAndSheep", 0, QApplication::UnicodeUTF8));
        gridview->setText(QString());
        groupBox->setTitle(QApplication::translate("WolfAndSheep_qtverClass", "Control", 0, QApplication::UnicodeUTF8));
        initializeB->setText(QApplication::translate("WolfAndSheep_qtverClass", "Initialize", 0, QApplication::UnicodeUTF8));
        startB->setText(QApplication::translate("WolfAndSheep_qtverClass", "Start", 0, QApplication::UnicodeUTF8));
        pauseB->setText(QApplication::translate("WolfAndSheep_qtverClass", "Pause", 0, QApplication::UnicodeUTF8));
        endB->setText(QApplication::translate("WolfAndSheep_qtverClass", "End", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("WolfAndSheep_qtverClass", "Setting", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WolfAndSheep_qtverClass", "SheepNum", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WolfAndSheep_qtverClass", "WolfNum", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WolfAndSheep_qtverClass", "Speed", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("WolfAndSheep_qtverClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\215\211\345\216\237\347\224\237\346\200\201\347\263\273\347\273\237\346\250\241\346\213\237</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\275\234\350\200\205\357\274\232\346\235\216\344\271\220\351\243\236</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\255\246\345\217\267\357\274\23212303075</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bloc"
                        "k-indent:0; text-indent:0px;\">\351\202\256\347\256\261\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sysullf@sina.com</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\266\211\345\217\212\347\256\227\346\263\225\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\244\232\346\231\272\350\203\275\344\275\223\343\200\201\350\264\252\345\277\203\347\256\227\346\263\225</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin"
                        "-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\217\202\346\225\260\350\214\203\345\233\264\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">SheepNum:[250,500]</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">WolfNum:[50,250]</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Speed:[50,500] \345\215\225\344\275\215:msc</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WolfAndSheep_qtverClass: public Ui_WolfAndSheep_qtverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WOLFANDSHEEP_QTVER_H
