QT += qml quick
TEMPLATE = app

CONFIG += c++17

SOURCES += \
        main.cpp

RESOURCES += qml.qrc \
    assets.qrc

INCLUDEPATH += source\
    ../cm-lib/source\
    ../cm-lib/

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib

message(Libs: $$PWD/../binaries/$$DESTINATION_PATH)

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Style.qml
