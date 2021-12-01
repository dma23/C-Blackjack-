#include "login.h"
#include "ui_login.h"
#include "data_utils.h"

string userString, passString;

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
   if (securityCheck(userString, passString, "data.csv")){
   }

}

void Login::on_pushButton_2_clicked()
{

  if (addPlayer("data.csv", userString, passString) ){

  }
}


void Login::on_user_textEdited(const QString &arg1)
{
   userString = arg1.toStdString();

}



void Login::on_password_textEdited(const QString &arg1)
{
    passString = arg1.toStdString();
}


void Login::on_user_textChanged(const QString &arg1)
{
    userString = arg1.toStdString();
}


void Login::on_password_textChanged(const QString &arg1)
{
    passString = arg1.toStdString();
}

