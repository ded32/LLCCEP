QT += widgets multimedia

INCLUDEPATH += $$PWD/../include/
CONFIG += gnu++11


SOURCES = codeReader/codeReader.cpp \
          window/window.cpp \
          window/renderer/renderer.cpp \
          softcore/softcore.cpp \
          mm/mm.cpp \
          ../lib/STDExtras.cpp \
          ../lib/command-line.cpp \
          main.cpp

HEADERS = codeReader/codeReader.hpp \
          window/window.hpp \
          window/renderer/renderer.hpp \
          softcore/softcore.hpp \
          softcore/fp.hpp \
          mm/mm.hpp
