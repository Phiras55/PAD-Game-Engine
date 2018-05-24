#-------------------------------------------------
#
# Project created by QtCreator 2018-04-27T09:51:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PAD-Engine
TEMPLATE = app


QMAKE_CXXFLAGS *= /std:c++17


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += \
        QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32:CONFIG(debug, debug|release){
LIBPATH = "../../Libs/lib/Debug/x64"
DLLPATH = "../../Libs/bin/Debug/x64"
}
win64:CONFIG(debug, debug|release){
LIBPATH = "../../Libs/lib/Debug/x64"
DLLPATH = "../../Libs/bin/Debug/x64"
}
win32:CONFIG(release, debug|release){
LIBPATH = "../../Libs/lib/Release/x64"
DLLPATH = "../../Libs/bin/Release/x64"
}
win64:CONFIG(release, debug|release){
LIBPATH = "../../Libs/lib/Release/x64"
DLLPATH = "../../Libs/bin/Release/x64"
}

HEADERPATH = "../../Libs/include"

INCLUDEPATH  += \
                "../../Libs/include/PAD Engine" \
                "../../Libs/include/PADRenderer"\
                "../../Libs/include/FBXSDK"\
                "../../Libs/include"

SOURCES += \
    main.cpp      \
    padeditor.cpp \
    transformwidget.cpp \
    padobjectwidget.cpp \
    boxcolliderwidget.cpp \
    sceneview.cpp

HEADERS += \
    padeditor.h                                         \
    glwidget.h											\
    transformwidget.h									\
    padobjectwidget.h									\
    boxcolliderwidget.h									\
    sceneview.h											\
    scenenode.h		#									\
    #"$$HEADERPATH/Pad Engine/System/ECS/PadObject.h"


RESOURCES +=\
        style.qrc

FORMS += \
        padeditor.ui \
        transformwidget.ui \
        padobjectwidget.ui \
        boxcolliderwidget.ui

LIBS += \
        "$$LIBPATH/PAD Engine.lib"\
        "$$LIBPATH/libfbxsdk-md.lib"\
        "$$LIBPATH/AssetParser.lib"
