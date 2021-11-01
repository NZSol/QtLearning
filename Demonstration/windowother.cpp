#include "windowother.h"
#include "ui_windowother.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
windowOther::windowOther(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowOther)
{
    ui->setupUi(this);
}

windowOther::~windowOther()
{
    delete ui;
}

void windowOther::on_ReadBtn_clicked(){
    QFile file(filePath);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Title", "No files selected");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->TextField->setPlainText(text);

    file.close();
}

void windowOther::on_WriteBtn_clicked(){
    QFile file(filePath);

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Title", "No files selected");
    }
    QTextStream out(&file);
    QString text = ui->TextField->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void windowOther::on_WriteAsBtn_clicked(){

    filePath = QFileDialog::getSaveFileName(this, "Select a file", "D:", "Filter(*txt)");
    QFile newFile(filePath);
    if(!newFile.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Title", "No file selected");
    }
    QTextStream out(&newFile);
    QString text = ui->TextField->toPlainText();
    out << text;
    newFile.flush();
    newFile.close();
}

void windowOther::on_SelectBtn_clicked(){
    QString filter = "File(*.*)";
    filePath = QFileDialog::getOpenFileName(this, "Select a file...", "D:", filter);
}

