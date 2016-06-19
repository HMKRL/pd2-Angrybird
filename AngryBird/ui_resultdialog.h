/********************************************************************************
** Form generated from reading UI file 'resultdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTDIALOG_H
#define UI_RESULTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resultDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QLabel *label_2;

    void setupUi(QDialog *resultDialog)
    {
        if (resultDialog->objectName().isEmpty())
            resultDialog->setObjectName(QStringLiteral("resultDialog"));
        resultDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(resultDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Retry);
        layoutWidget = new QWidget(resultDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 30, 401, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(lcdNumber, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("TakaoPGothic"));
        font1.setPointSize(26);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(resultDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), resultDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), resultDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(resultDialog);
    } // setupUi

    void retranslateUi(QDialog *resultDialog)
    {
        resultDialog->setWindowTitle(QApplication::translate("resultDialog", "Result", 0));
        label->setText(QApplication::translate("resultDialog", "TextLabel", 0));
        label_2->setText(QApplication::translate("resultDialog", "SCORE:", 0));
    } // retranslateUi

};

namespace Ui {
    class resultDialog: public Ui_resultDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTDIALOG_H
