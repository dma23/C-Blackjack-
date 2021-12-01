#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //add all the other ui
//    Login *login;

private:
    Ui::MainWindow *ui;
private slots:
    //main menu buttons
    void on_blackjackBtn_clicked();
    void on_slotsBtn_clicked();

    //top buttons
    void on_returnToMain_clicked();
    void on_changeUserBtn_clicked();
    void exitCurrentGamePrompt();

    //talk to children
    void returnToMain();
};




#endif // MAINWINDOW_H
