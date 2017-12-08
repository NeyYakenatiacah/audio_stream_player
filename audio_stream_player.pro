LIBVLC = $$(LIBVLC_PATH)
BOOST  = $$(BOOST_PATH)

isEmpty(LIBVLC) {
   warning("You have to set LIBVLC_PATH variable!")
}

isEmpty(BOOST) {
   #warning("You have to set BOOST_PATH variable!")
}

INCLUDEPATH += $$LIBVLC/include

CONFIG(debug, debug|release) {
    LIBS += -L$$LIBVLC/lib
    LIBS += -lVLCQtCored
}

CONFIG(release, debug|release) {
    LIBS += -L$$LIBVLC/lib
    LIBS += -lVLCQtCore
}


QT += qml quick widgets
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD/content

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
#    streamplayer.h \
#    settings.h \
#    source.h \
#    iplayer.h \
#    Containers/mediasource.h \
#    Containers/constants.h \
    media_controller.h \
    Containers/media_source.h \
    Containers/media_list.h \
    Containers/meta_data.h

SOURCES += main.cpp \
#    streamplayer.cpp \
#    settings.cpp \
#    source.cpp \
#    Containers/mediasource.cpp \
    media_controller.cpp \
    Containers/media_source.cpp \
    Containers/media_list.cpp \
    Containers/meta_data.cpp
