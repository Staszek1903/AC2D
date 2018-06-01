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
    DrawSystem.cpp \
    Body.cpp \
    Functions.cpp \
    GameplayStage.cpp \
    GameStage.cpp \
    MenuStage.cpp

HEADERS += \
    ResourcesManager.h \
    ECSGameplay.h \
    ExitStage.h \
    DrawSystem.h \
    ClassesDeclarations.h \
    Body.h \
    Functions.h \
    GameplayStage.h \
    GameStage.h \
    LibsAndDeclarations.h \
    MenuStage.h
