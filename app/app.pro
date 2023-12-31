QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
DESTDIR     = $$OUT_PWD/../bin
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    AppWindow.cc

HEADERS += \
    AppWindow.h

FORMS += \
    AppWindow.ui

include(../components/Buttons/EditableButton/EditableButton.pri)
include(../components/Buttons/LongPressButton/LongPressButton.pri)
include(../components/TableWidget/DragableTableWidget/DragableTableWidget.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


INCLUDEPATH += ../dynamic_libraries/FooAPI
LIBS += -L$$DESTDIR -lFooAPI
