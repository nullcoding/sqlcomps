HEADERS       = db.h \
    id_class_lists.h \
    newentrydialog.h \
    ramentrydialog.h \
    mainpage.h \
    model.h
SOURCES       = \
    main.cpp \
    model.cpp \
    newentrydialog.cpp \
    ramentrydialog.cpp \
    mainpage.cpp \
    hdd_class_list.cpp \
    ram_class_list.cpp
QT           += sql widgets

INCLUDEPATH += "C:\Qt\Qt5.1.1\5.1.1\msvc2012_64\lib"
win32:
LIBS += $$PWD\lib\libmysql.lib

# install
target.path = built/
INSTALLS += target

FORMS += \
    mainpage.ui \
    newentrydialog.ui \
    ramentrydialog.ui

RESOURCES += \
    rc.qrc

OTHER_FILES += \
    icon/ncs.jpg
