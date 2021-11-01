#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowother.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Pass->setEchoMode(QLineEdit::Password);
    ui->Title->setStyleSheet("QLabel{font-size:24px}");
    QPixmap Img(":/resources/Images/Null_Img.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
    ui->statusbar->addPermanentWidget(ui->progressStatus, 1);
    ui->statusbar->addPermanentWidget(ui->LabelStatus, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_clicked()
{
    QString user = ui->lineEdit_User->text();
    QString pass = ui->lineEdit_Pass->text();

    if(user == "test" && pass == "test"){
        //QMessageBox::information(this, "Login", "Welcome Back");
        ui->statusbar->showMessage("Login Succesful", 1000);
        window = new windowOther(this);
        window->show();
    }
    else{
        QMessageBox::warning(this, "Login", "Incorrect username or password");
    }

//    windowOther window;
//    window.setModal(true);
//    window.exec();

}


void MainWindow::on_passDisplay_stateChanged(int i)
{
    switch(i){
    case 0:
        ui->lineEdit_Pass->setEchoMode(QLineEdit::Password);
        break;
    case 2:
        ui->lineEdit_Pass->setEchoMode(QLineEdit::Normal);
        break;
    }

}

void MainWindow::on_actionNew_triggered(){
    QMessageBox::information(this, "title", "File > New Pressed");
}

