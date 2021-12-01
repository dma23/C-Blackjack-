#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMessageBox>
#include <QShortcut>
#include <QWidget>
#include <QStackedWidget>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //add all the widgets for the games and such
    //login
//    login = new Login;
//    connect(login, SIGNAL(changeToMain()), this,SLOT(returnToMain()));
//    ui->stackedWidget->addWidget(login);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::returnToMain(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_blackjackBtn_clicked(){

}
void MainWindow::on_slotsBtn_clicked(){

}
void MainWindow::on_returnToMain_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Test", "Quit?",QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        ui->stackedWidget->setCurrentIndex(0);
        QApplication::quit();
      } else {
        qDebug() << "Yes was *not* clicked";
      }
}
void MainWindow::on_changeUserBtn_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::exitCurrentGamePrompt(){

}

