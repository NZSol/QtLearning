#ifndef WINDOWOTHER_H
#define WINDOWOTHER_H

#include <QDialog>

namespace Ui {
class windowOther;
}

class windowOther : public QDialog
{
    Q_OBJECT

public:
    explicit windowOther(QWidget *parent = nullptr);
    ~windowOther();
    QString filePath;

private slots:
    void on_ReadBtn_clicked();
    void on_WriteBtn_clicked();
    void on_SelectBtn_clicked();
    void on_WriteAsBtn_clicked();

private:
    Ui::windowOther *ui;
};

#endif // WINDOWOTHER_H
