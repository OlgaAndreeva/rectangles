TEMPLATE = app
QT += qml quick gui
QT += core
CONFIG += c++11

SOURCES += main.cpp \
    colormodel.cpp \
    appobject.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    colormodel.h \
    appobject.h