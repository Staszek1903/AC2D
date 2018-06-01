TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
LIBS += -lentityx

SOURCES += \
        main.cpp \
    ResourcesManager.cpp \
    ECSGameplay.cpp \
    ExitStage.cpp \
    Functions.cpp \
    GameplayStage.cpp \
    GameStage.cpp \
    MenuStage.cpp \
    RenderSystem.cpp \
    Components/position.cpp \
    Components/velocity.cpp \
    Components/rotation.cpp \
    Systems/movementsystem.cpp \
    Systems/RenderSystem.cpp

HEADERS += \
    ResourcesManager.h \
    ECSGameplay.h \
    ExitStage.h \
    ClassesDeclarations.h \
    Functions.h \
    GameplayStage.h \
    GameStage.h \
    LibsAndDeclarations.h \
    MenuStage.h \
    RenderSystem.h \
    Components/position.h \
    Components/velocity.h \
    Components/rotation.h \
    Systems/movementsystem.h \
    Systems/RenderSystem.h
