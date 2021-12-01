#include "Blackjackwindow.h"
#include "ui_Blackjackwindow.h"
#include "blackjack.h"
#include <iostream>
#include <QStandardPaths>
#include <QCoreApplication>
#include <QDir>
#include <vector>
using namespace std;
Blackjackwindow::Blackjackwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_p1, &QPushButton::released, this, &Blackjackwindow::betp1);
    connect(ui->btn_p5, &QPushButton::released, this, &Blackjackwindow::betp5);
    connect(ui->btn_p10, &QPushButton::released, this, &Blackjackwindow::betp10);
    connect(ui->btn_m1, &QPushButton::released, this, &Blackjackwindow::betm1);
    connect(ui->btn_m5, &QPushButton::released, this, &Blackjackwindow::betm5);
    connect(ui->btn_m10, &QPushButton::released, this, &Blackjackwindow::betm10);


    connect(ui->btn_stand, &QPushButton::released, this, &Blackjackwindow::stand);
    connect(ui->btn_hit, &QPushButton::released, this, &Blackjackwindow::hit);
    connect(ui->btn_go, &QPushButton::released, this, &Blackjackwindow::play);
    connect(ui->btn_double, &QPushButton::released, this, &Blackjackwindow::doublePlay);
}

void Blackjackwindow::bet(int bet) {
    casino.bet(bet);
    ui->lb_bet->setText(QString::fromStdString("Bet: " + to_string(casino.get_cur_bet())));
}
void Blackjackwindow::betp1() {
    bet(1);
}
void Blackjackwindow::betp5() {
    bet(5);
}
void Blackjackwindow::betp10() {
    bet(10);
}
void Blackjackwindow::betm1() {
    bet(-1);
}
void Blackjackwindow::betm5() {
    bet(-5);
}
void Blackjackwindow::betm10() {
    bet(-10);
}


void Blackjackwindow::doublePlay() {
    casino.double_down();
    showHand();
    showDealerHand();
}

void Blackjackwindow::hit() {
    casino.hit();
    showHand();
    showDealerHand();

}

void Blackjackwindow::stand(){
    casino.stand();
    showHand();
    showDealerHand();

}

void Blackjackwindow::play(){
    casino.play_game();
    showHand();
    showDealerHand();

}

void Blackjackwindow::showHand() {
    vector<string> cards = casino.get_player_hand();
    QDir dir;
    string fold = dir.absolutePath().toStdString() + "/images/cards/";
    string dest;
    QImage img;
    int count = 0;
    for (const auto& card : cards) {
        dest = fold + card + ".png";

        img.load(QString::fromStdString(dest));
        QPixmap pix = QPixmap::fromImage(img);
        QPixmap scaled = pix.scaled(100, 145);
        if (count==0)
            ui->lb_p1->setPixmap(scaled);
        if (count==1)
            ui->lb_p2->setPixmap(scaled);
        if (count==2)
            ui->lb_p3->setPixmap(scaled);
        if (count==3)
            ui->lb_p4->setPixmap(scaled);
        if (count==4)
            ui->lb_p5->setPixmap(scaled);
        count++;
    }
}

void Blackjackwindow::showDealerHand() {
    vector<string> cards = casino.get_dealer_hand();
    QDir dir;
    string fold = dir.absolutePath().toStdString() + "/images/cards/";
    string dest;
    QImage img;
    int count = 0;
    for (const auto& card : cards) {
        if (count==0) {
            dest = fold + card + ".png";

            img.load(QString::fromStdString(dest));
            QPixmap pix = QPixmap::fromImage(img);
            QPixmap scaled = pix.scaled(100, 145);

            ui->lb_d1->setPixmap(scaled);
        }
        else {
            dest = fold  + "back.jpg";
            img.load(QString::fromStdString(dest));
            QPixmap pix = QPixmap::fromImage(img);
            QPixmap scaled = pix.scaled(100, 145);
            if (count == 1)
                ui->lb_d2->setPixmap(scaled);
            if (count == 2)
                ui->lb_d3->setPixmap(scaled);
            if (count == 3)
                ui->lb_d4->setPixmap(scaled);
            if (count == 4)
                ui->lb_d5->setPixmap(scaled);
        }
        count++;
    }
}

Blackjackwindow::~Blackjackwindow()
{
    delete ui;
}

