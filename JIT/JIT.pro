QT += widgets multimedia network

INCLUDEPATH += ./../include/

HEADERS = rex/rex.hpp \
          codegen/codegen.hpp \
          emitter/emitter.hpp \
          program/program.hpp \
          rm-field/rm-field.hpp \
          startup/program.hpp \
          startup/startup.hpp \
          runtime/runtime.hpp

SOURCES = codegen/codegen.cpp \
          emitter/emitter.cpp \
          program/program.cpp \
          rm-field/rm-field.cpp \
          startup/startup.cpp \
          main.cpp \
    stack-protector/stack-protector.cpp
