QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Blackjackwindow.cpp \
    blackjack.cpp \
    main.cpp

HEADERS += \
    Blackjackwindow.h \
    blackjack.h

FORMS += \
    Blackjackwindow.ui

TRANSLATIONS += \
    basicexample_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/cards/10c.png \
    images/cards/10d.png \
    images/cards/10h.png \
    images/cards/10s.png \
    images/cards/2c.png \
    images/cards/2d.png \
    images/cards/2h.png \
    images/cards/2s.png \
    images/cards/3c.png \
    images/cards/3d.png \
    images/cards/3h.png \
    images/cards/3s.png \
    images/cards/4c.png \
    images/cards/4d.png \
    images/cards/4h.png \
    images/cards/4s.png \
    images/cards/5c.png \
    images/cards/5d.png \
    images/cards/5h.png \
    images/cards/5s.png \
    images/cards/6c.png \
    images/cards/6d.png \
    images/cards/6h.png \
    images/cards/6s.png \
    images/cards/7c.png \
    images/cards/7d.png \
    images/cards/7h.png \
    images/cards/7s.png \
    images/cards/8c.png \
    images/cards/8d.png \
    images/cards/8h.png \
    images/cards/8s.png \
    images/cards/9c.png \
    images/cards/9d.png \
    images/cards/9h.png \
    images/cards/9s.png \
    images/cards/ac.png \
    images/cards/ad.png \
    images/cards/ah.png \
    images/cards/as.png \
    images/cards/jc.png \
    images/cards/jd.png \
    images/cards/jh.png \
    images/cards/js.png \
    images/cards/kc.png \
    images/cards/kd.png \
    images/cards/kh.png \
    images/cards/ks.png \
    images/cards/qc.png \
    images/cards/qd.png \
    images/cards/qh.png \
    images/cards/qs.png
