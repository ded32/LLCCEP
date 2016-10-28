# LLCCEP
LLCCEP is Low-Level Code Compilation Execution Platform.

# Aims of the project
The main aim of project is to provide cross-platform
machine-independent toolkit for development of
programs.

Now, the platform has already implemented assembly language
and machine-independent interpreter for programs, 
written in it, compiled into bytecode via developed assembler.

And now, JIT and AOT compilers are being implemented. Their
aim is to maximise speed of execution to increase platform's 
urgency and usability.

And one more aim of the project is to develop easy-transferable
environment of program and make interaction between it and
program the simplest possible. As the platform provides
OS-abstragated subsystem of graphics, the QT library was
used to implement it. Also, there is OS-independent work
with files, was implemented with basic libc functions and
types.

# TODO LIST
Debug, JIT and AOT compilers 

# BUGTRACKER
Report about bugs [here](https://github.com/Andrew-Bezzubtsev/LLCCEP/issues/new)
