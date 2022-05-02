QT -= gui

TEMPLATE = lib
DEFINES += CM2LIB_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    command.cpp \
    commandcontroller.cpp \
    datadecorator.cpp \
    datetimedecorator.cpp \
    entity.cpp \
    enumeratordecorator.cpp \
    intdecorator.cpp \
    master-controller.cpp \
    stringdecorator.cpp

HEADERS += \
    cm2-lib_global.h \
    client.h \
    command.h \
    commandcontroller.h \
    datadecorator.h \
    datetimedecorator.h \
    entity.h \
    entitycollection.h \
    enumeratordecorator.h \
    intdecorator.h \
    master-controller.h \
    navigation-controller.h \
    stringdecorator.h

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
