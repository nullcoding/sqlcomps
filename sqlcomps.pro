HEADERS       = mainpage.h \
    db.h \
    id_class_lists.h \
    newentrydialog.h \
    model.h
SOURCES       = main.cpp \
    id_class_lists.cpp \
    mainpage.cpp \
    model.cpp \
    newentrydialog.cpp
QT           += sql widgets

INCLUDEPATH += "C:\Qt\Qt5.1.1\5.1.1\msvc2012_64\lib"
win32:
LIBS += $$PWD\lib\libmysql.lib

# install
target.path = built/
INSTALLS += target

FORMS += \
    mainpage.ui \
    newentrydialog.ui
