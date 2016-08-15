QT += widgets

INCLUDEPATH += $$PWD/../include/

SOURCES = program/program.cpp \
          window/window.cpp \
          window/renderer/renderer.cpp \
          softcore/softcore.cpp \
          mm/mm.cpp \
          ../lib/STDExtras.cpp \
          main.cpp \
    mm/mm.cpp

HEADERS = program/program.hpp \
          window/window.hpp \
          window/renderer/renderer.hpp \
          softcore/softcore.hpp \
          softcore/fp.hpp \
          mm/mm.hpp \
    mm/mm.hpp