# Assembler of LLCCEP

The assembler for Low-Level Code Compilation Execution Platform.
This program tranlates programs in LLCCEP_asm language into 
LLCCEP bytecode, which can be executed on emulator, or translated 
to native machine code.

# Building the assembler

This program has no dependencies on non-standard libraries like Boost or Qt.
All you need is to type

    cmake .; make

The build was tested on the Clang-703.0.31. Building on GCC also occurs
OK, but I recommend you using Clang.

# Assembly

The syntax of assembly language is trivial. But there are some differences between x86
assembly and LLCCEP assembly.

Remarks:
* Here, and after PC is used as determiner of Program Counter
* sleep(0) means not nothing, but the shortest possible delay

Instructions list:
* mov dest, source          | dest := source
* mva dest, source          | \*dest := source
* push source               | st(top) := source
* pop                       | delete st(top)
* top dest                  | dest := st(top)
* add dest, s0, s1          | dest := s0 + s1
* sub dest, s0, s1          | dest := s0 - s1
* mul dest, s0, s1          | dest := s0 \* s1
* div dest, s0, s1          | dest := s0 / s1
* and dest, s0, s1          | dest := s0 & s1
* or  dest, s0, s1          | dest := s0 | s1
* xor dest, s0, s1          | dest := s0 ^ s1
* off dest, s0, s1          | dest := s0 << s1
* nop                       | sleep(0)
* swi id                    | runtime call $id
* cmp s0, s1                | compare s0 to s1 and process flags
* inc source                | source := source + 1
* dec source                | source := source - 1
* sqrt dest, source         | dest := sqrt(source)
* sin dest, source          | dest := sin(source)
* cos dest, source          | dest := cos(source)
* ptan dest, source         | dest := ptan(source)
* patan dest, source        | dest := patan(source)
* ldc id                    | load constant $id
* outp pid, val             | pid <- val (write val to port $pid)
* inp pid, val              | pid -> val (read val from port $pid)
* call abs                  | call function at $abs
* jmp abs                   | PC := abs
* ret                       | return to the top-level function. If done in _main, ends program.

Registers:
There are 32 registers: from 00 to 31.
The determination of register looks like: &id, where id is register id.
Register can specify both destination and source.

Memory:
Memory addressing comes from zero, as traditional.
To specify memory address you need to write: $off, where off is offset from the memory
beginning in memory elements.
Memory address can specify both destination and source.

Numbers:
Numbers are only floating-point with double percision.
So, they're 8-bytes in length and they are chosen as memory elements.
Numbers can only specify a source.

Labels:
You can place labels everywhere you want. Both before instructions and other labels.
Every label name will be replaced with the address of instruction after it.
So, label name becomes a number, when you place it as an argument.
As the consequence, label name can only specify a source.