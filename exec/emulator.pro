QT += widgets multimedia

INCLUDEPATH += $$PWD/../include/
CONFIG += gnu++11

QMAKE_LFLAGS += -v

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
