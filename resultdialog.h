#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>
#include <QSound>

namespace Ui {
class resultDialog;
}

class resultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit resultDialog(int Score, int enemy, int bird, QWidget *parent = 0);
    ~resultDialog();

private:
    Ui::resultDialog *ui;
};

#endif // RESULTDIALOG_H
