QT += widgets multimedia

INCLUDEPATH += ./../include/
CONFIG += gnu++14 debug

QMAKE_CXXFLAGS_DEBUG += -g -O0
QMAKE_CXXFLAGS_RELEASE += -flto -Ofast \
                          -march=native \
                          -funroll-loops \

SOURCES = codeReader/codeReader.cpp \
          window/window.cpp \
          window/renderer/renderer.cpp \
          softcore/softcore.cpp \
          mm/mm.cpp \
          signal/signal.cpp \
          ../lib/STDExtras.cpp \
          ../lib/command-line.cpp \
          main.cpp \
          messageBox/messageBox.cpp

HEADERS = codeReader/codeReader.hpp \
          window/window.hpp \
          window/renderer/renderer.hpp \
          softcore/softcore.hpp \
          softcore/fp.hpp \
          mm/mm.hpp \
          signal/signal.hpp \
          messageBox/messageBox.hpp

TARGET  = "LLCCEP Emulator"
