TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
LIBS += -lentityx

SOURCES += \
        main.cpp \
    ECSGameplay.cpp \
    ExitStage.cpp \
    Functions.cpp \
    GameplayStage.cpp \
    GameStage.cpp \
    MenuStage.cpp \
    ResourcesManager.cpp \
    Systems/RenderSystem.cpp \
    Systems/movementsystem.cpp \
    Components/velocity.cpp \
    Components/rotation.cpp \
    Components/position.cpp

HEADERS += \
    ClassesDeclarations.h \
    ECSGameplay.h \
    ExitStage.h \
    Functions.h \
    GameplayStage.h \
    GameStage.h \
    LibsAndDeclarations.h \
    MenuStage.h \
    ResourcesManager.h \
    Components.h \
    Systems/RenderSystem.h \
    Systems/movementsystem.h \
    Components/velocity.h \
    Components/rotation.h \
    Components/position.h

DISTFILES += \
    CMakeLists.txt
