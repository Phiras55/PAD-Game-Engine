#-------------------------------------------------
#
# Project created by QtCreator 2018-04-27T09:51:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PAD-Engine
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32:CONFIG(debug, debug|release){
LIBPATH = "../../Libs/lib/Debug/Win32"
DLLPATH = "../../Libs/bin/Debug/Win32"
}
win64:CONFIG(debug, debug|release){
LIBPATH = "../../Libs/lib/Debug/x64"
DLLPATH = "../../Libs/bin/Debug/x64"
}
win32:CONFIG(release, debug|release){
LIBPATH = "../../Libs/lib/Release/Win32"
DLLPATH = "../../Libs/bin/Release/Win32"
}
win64:CONFIG(release, debug|release){
LIBPATH = "../../Libs/lib/Release/x64"
DLLPATH = "../../Libs/bin/Release/x64"
}

HEADERPATH = "../../Libs/include"

INCLUDEPATH  += \
                "../../Libs/include/PAD Engine" \
                "../../Libs/include/PADRenderer"\
                "../../Libs/include"

SOURCES += \
        main.cpp        \
        padeditor.cpp

HEADERS += \
       padeditor.h														\
        "$$HEADERPATH/PAD Engine/Core/Engine.h"							\
        "$$HEADERPATH/PAD Engine/Core/EngineClock.h"					\
        "$$HEADERPATH/PAD Engine/Core/EngineDLL.h"						\
        "$$HEADERPATH/PAD Engine/Core/IDPool.h"							\
        "$$HEADERPATH/PAD Engine/Core/Timer.h"							\
        "$$HEADERPATH/PAD Engine/Graphics/HighLevelRenderer.h"			\
        "$$HEADERPATH/PAD Engine/System/ECS/ACollider.h"				\
        "$$HEADERPATH/PAD Engine/System/ECS/AScriptComponent.h"			\
        "$$HEADERPATH/PAD Engine/System/ECS/BoxCollider.h"				\
        "$$HEADERPATH/PAD Engine/System/ECS/Camera.h"					\
        "$$HEADERPATH/PAD Engine/System/ECS/Collider.h"					\
        "$$HEADERPATH/PAD Engine/System/ECS/IComponent.h"				\
        "$$HEADERPATH/PAD Engine/System/ECS/MeshRenderer.h"				\
        "$$HEADERPATH/PAD Engine/System/ECS/PADObject.h"				\
        "$$HEADERPATH/PAD Engine/System/ECS/PerspectiveCamera.h"		\
        "$$HEADERPATH/PAD Engine/System/ECS/RigidBody.h"				\
        "$$HEADERPATH/PAD Engine/System/ECS/Scene.h"					\
        "$$HEADERPATH/PAD Engine/System/Physics/BulletContext.h"		\
        "$$HEADERPATH/PAD Engine/System/Physics/IPhysicContext.h"		\
        "$$HEADERPATH/PAD Engine/System/Resource/AResourceManager.h"	\
        "$$HEADERPATH/PAD Engine/System/Resource/MasterManager.h"		\
        "$$HEADERPATH/PAD Engine/System/Resource/MeshManager.h"			\
        "$$HEADERPATH/PAD Engine/System/Resource/Resource.h"			\
        "$$HEADERPATH/PAD Engine/System/Resource/ResourceManager.h"		\
        "$$HEADERPATH/PAD Engine/System/Window/AWindow.h"				\
        "$$HEADERPATH/PAD Engine/System/Window/IWindowBase.h"			\
        "$$HEADERPATH/PAD Engine/System/Window/SDLWindow.h"				\
        "$$HEADERPATH/PAD Engine/System/Window/WindowSettings.h"		\
        "$$HEADERPATH/PAD Engine/System/IModule.h"						\
        "$$HEADERPATH/PAD Engine/Utilities/EnumUtils.h"					\
        "$$HEADERPATH/PAD Engine/Utilities/Export.h"					\
        "$$HEADERPATH/PAD Engine/Utilities/Randomizer.h"				\
        "$$HEADERPATH/PADRenderer/Graphics/GL/Shader/*.h"				\
        "$$HEADERPATH/PADRenderer/Graphics/GL/*.h"						\
        "$$HEADERPATH/PADRenderer/Graphics/Model/*.h"					\
        "$$HEADERPATH/PADRenderer/Graphics/RHI/Shader/*.h"				\
        "$$HEADERPATH/PADRenderer/Graphics/RHI/*.h"						\
        "$$HEADERPATH/PADRenderer/Graphics/Window/*.h"



FORMS += \
        padeditor.ui

LIBS += \
        "$$LIBPATH/PAD Engine.lib"\
        "$$LIBPATH/PADRenderer.lib"
