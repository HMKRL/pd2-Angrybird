#include "resultdialog.h"
#include "ui_resultdialog.h"

resultDialog::resultDialog(int Score, int enemy, int bird, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultDialog)
{
    ui->setupUi(this);
    ui->lcdNumber->display(Score + bird * 10000);
    if(enemy) {
        ui->label->setText("Level Failed...");
        QSound::play(":/sound/res/fail.wav");
    }
    else {
        ui->label->setText("Level Clear!");
        QSound::play(":/sound/res/success.wav");
    }
}

resultDialog::~resultDialog()
{
    delete ui;
}
