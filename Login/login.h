#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_password_editingFinished();

    void on_label_5_linkActivated(const QString &link);

    void on_password_textEdited(const QString &arg1);

    void on_password_textChanged(const QString &arg1);

    void on_user_textEdited(const QString &arg1);

    void on_error_message_linkActivated(const QString &link);

    void on_user_textChanged(const QString &arg1);

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
