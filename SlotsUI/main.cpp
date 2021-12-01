#include <QtWidgets>
#include <qmath.h>
#include <QRandomGenerator>

#include "wheelwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(bool touch)
        : QMainWindow()
    {
        makeSlotMachine(touch);
        setCentralWidget(m_slotMachine);
    }

    void makeSlotMachine(bool touch)
    {
        QSize size = QApplication::screens()[0]->size();
        if (size.width() > 1000) {
            QFont f = font();
            f.setPointSize(f.pointSize() * 2);
            setFont(f);
        }

        m_slotMachine = new QWidget(this);
        QGridLayout *grid = new QGridLayout(m_slotMachine);
        grid->setSpacing(20);

        QStringList colors;
        colors << "Red" << "Magenta" << "Peach" << "Orange" << "Yellow" << "Citro" << "Green" << "Cyan" << "Blue" << "Violet";

        m_wheel1 = new StringWheelWidget(touch);
        m_wheel1->setItems( colors );
        grid->addWidget( m_wheel1, 0, 0 );

        m_wheel2 = new StringWheelWidget(touch);
        m_wheel2->setItems( colors );
        grid->addWidget( m_wheel2, 0, 1 );

        m_wheel3 = new StringWheelWidget(touch);
        m_wheel3->setItems( colors );
        grid->addWidget( m_wheel3, 0, 2 );

        QPushButton *shakeButton = new QPushButton(tr("Spin"));
        connect(shakeButton, SIGNAL(clicked()), this, SLOT(rotateRandom()));

        grid->addWidget( shakeButton, 1, 0, 1, 3 );
    }

private slots:
    void rotateRandom()
    {
        QRandomGenerator *qrand = QRandomGenerator::system();
        m_wheel1->scrollTo(m_wheel1->currentIndex() + (qrand->bounded(200)));
        m_wheel2->scrollTo(m_wheel2->currentIndex() + (qrand->bounded(200)));
        m_wheel3->scrollTo(m_wheel3->currentIndex() + (qrand->bounded(200)));
    }

private:
    QWidget *m_slotMachine;

    StringWheelWidget *m_wheel1;
    StringWheelWidget *m_wheel2;
    StringWheelWidget *m_wheel3;
};

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    bool touch = a.arguments().contains(QLatin1String("--touch"));
    MainWindow mw(touch);
#ifdef Q_WS_S60
    mw.showMaximized();
#else
    mw.show();
#endif
#ifdef Q_WS_MAC
    mw.raise();
#endif
    return a.exec();
}

#include "main.moc"
