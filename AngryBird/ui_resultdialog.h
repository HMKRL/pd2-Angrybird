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
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_resultDialog
{
public:
    QDialogButtonBox *buttonBox;

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

        retranslateUi(resultDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), resultDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), resultDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(resultDialog);
    } // setupUi

    void retranslateUi(QDialog *resultDialog)
    {
        resultDialog->setWindowTitle(QApplication::translate("resultDialog", "Result", 0));
    } // retranslateUi

};

namespace Ui {
    class resultDialog: public Ui_resultDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTDIALOG_H
