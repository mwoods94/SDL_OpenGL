TARGET=SDLOpenGL

OBJECTS_DIR=obj
SOURCES+=$$PWD/src/main.cpp
         $$PWD/src/SDLOpenGL.cpp

HEADERS+=$$PWD/include/SDLOpenGl.h

include($(HOME)/NGL/UseNGL.pri)
