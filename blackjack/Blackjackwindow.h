#ifndef BLACKJACKWINDOW_H
#define BLACKJACKWINDOW_H

#include <QMainWindow>
#include "blackjack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Blackjackwindow : public QMainWindow
{
    Q_OBJECT

public:
    Blackjackwindow(QWidget *parent = nullptr);
    ~Blackjackwindow();
    void mainMenu();
    void bet( int bet);
    void hit();
    void stand();
    void play();
    void doublePlay();
    void showHand();
    void showDealerHand();
    void betp1();
    void betp5();
    void betp10();
    void betm1();
    void betm5();
    void betm10();
private:
    Ui::MainWindow *ui;
    blackjack casino;
};
#endif // Blackjackwindow_H
