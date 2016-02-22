TARGET=SDLOpenGL

OBJECTS_DIR=obj
INCLUDEPATH+=$$PWD/include

SOURCES+=$$PWD/src/main.cpp \
         $$PWD/src/SDLOpenGl.cpp

HEADERS+=$$PWD/include/SDLOpenGl.h
QMAKE_CXXFLAGS += $$system(sdl2-config --cflags)
LIBS+=$$system(sdl2-config --libs)
include($(HOME)/NGL/UseNGL.pri)
OTHER_FILES += README.md
