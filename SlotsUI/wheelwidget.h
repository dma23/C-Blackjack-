
#ifndef WHEELWIDGET_H
#define WHEELWIDGET_H

#include <QWidget>
#include <QStringList>

class QPainter;
class QRect;

class AbstractWheelWidget : public QWidget {
    Q_OBJECT

public:
    AbstractWheelWidget(bool touch, QWidget *parent = 0);
    virtual ~AbstractWheelWidget();

    int currentIndex() const;
    void setCurrentIndex(int index);

    bool event(QEvent*);
    void paintEvent(QPaintEvent *e);
    virtual void paintItem(QPainter* painter, int index, const QRect &rect) = 0;

    virtual int itemHeight() const = 0;
    virtual int itemCount() const = 0;

public slots:
    void scrollTo(int index);

signals:
    void stopped(int index);

protected:
    int m_currentItem;
    int m_itemOffset; // 0-itemHeight()
    qreal m_lastY;
};

class StringWheelWidget : public AbstractWheelWidget {
    Q_OBJECT

public:
    StringWheelWidget(bool touch);

    QStringList items() const;
    void setItems( const QStringList &items );

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    void paintItem(QPainter* painter, int index, const QRect &rect);

    int itemHeight() const;
    int itemCount() const;

private:
    QStringList m_items;
};

#endif // WHEELWIDGET_H
