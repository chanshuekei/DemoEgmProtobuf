QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

VERSION=1.0.0.0
RC_LANG=0x0004
QMAKE_TARGET_PRODUCT=EmgProtobuf
QMAKE_TARGET_COMPANY=MoonTypist@CHANSHUEKEI
QMAKE_TARGET_COPYRIGHT=Right(C)2025

DEFINES += PROGRAM_VER=\\\"$$VERSION\\\"
DEFINES += AUTHOR=\\\"CHANSHUKEI\\\"

TARGET = DemoEgmProtobuf
TEMPLATE = app
DESTDIR = ./Bin/

SOURCES += \
    main.cpp \
    egmprotobufwin.cpp \
    egm/egm.pb.cc \

HEADERS += \
    egmprotobufwin.h \
    egm/egm.pb.h

FORMS += \
    egmprotobufwin.ui

INCLUDEPATH += $$PWD/egm/
INCLUDEPATH += $$PWD/protobuf/include/
INCLUDEPATH += $$PWD/protobuf/lib/

# 添加依赖库
contains(QT, debug) {
    LIBS += -L$$PWD/protobuf/lib/ -llibprotobufd
} else {
    LIBS += -L$$PWD/protobuf/lib/ -llibprotobuf
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
