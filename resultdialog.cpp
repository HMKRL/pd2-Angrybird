#include "resultdialog.h"
#include "ui_resultdialog.h"

resultDialog::resultDialog(int Score, int enemy, int bird, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultDialog)
{
    ui->setupUi(this);
}

resultDialog::~resultDialog()
{
    delete ui;
}
