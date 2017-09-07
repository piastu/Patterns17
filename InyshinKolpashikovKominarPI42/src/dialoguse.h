#ifndef DIALOGUSE_H
#define DIALOGUSE_H

#include <QDialog>

namespace Ui {
class DialogUse;
}

class DialogUse : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUse(QWidget *parent = 0);
    bool getUsed();
    ~DialogUse();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DialogUse *ui;
    bool used;
};

#endif // DIALOGUSE_H
