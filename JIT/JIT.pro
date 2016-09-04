QT += widgets multimedia network

INCLUDEPATH += ./../include/

HEADERS = rex/rex.hpp \
          codegen/codegen.hpp \
          emitter/emitter.hpp \
          program/program.hpp \
          rm-field/rm-field.hpp \
          startup/program.hpp \
          startup/startup.hpp \
          runtime/runtime.hpp \
          ../exec/softcore/softcore.hpp \
          ../exec/mm/mm.hpp \
          ../exec/codeReader/codeReader.hpp \
          ../exec/window/window.hpp \
          ../exec/window/renderer/renderer.hpp \
          ../exec/signal/signal.hpp \
          ../exec/messageBox/messageBox.hpp

SOURCES = codegen/codegen.cpp \
          emitter/emitter.cpp \
          program/program.cpp \
          rm-field/rm-field.cpp \
          startup/startup.cpp \
          main.cpp \
          stack-protector/stack-protector.cpp\
          ../lib/STDExtras.cpp \
          runtime/runtime.cpp \
          ../exec/softcore/softcore.cpp \
          ../exec/mm/mm.cpp \
          ../exec/codeReader/codeReader.cpp \
          ../exec/window/window.cpp \
          ../exec/window/renderer/renderer.cpp \
          ../exec/messageBox/messageBox.cpp \
          ../lib/command-line.cpp \
          ../exec/signal/signal.cpp \
