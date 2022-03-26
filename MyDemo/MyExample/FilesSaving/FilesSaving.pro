TEMPLATE = app
CONFIG += console c++11
CONFIG += app_bundle
CONFIG += qt
QT += sql
SOURCES += \
        CSVFormat.cpp \
        DBFormat.cpp \
        FilesFormat.cpp \
        PersonDetails.cpp \
        main.cpp
#DESTDIR = $$PWD/bins
HEADERS += \
    CSVFormat.h \
    CommonUtils.h \
    DBFormat.h \
    FilesFormat.h \
    PersonDetails.h
