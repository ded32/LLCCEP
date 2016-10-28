# Assembler of LLCCEP

The assembler for Low-Level Code Compilation Execution Platform.
This program tranlates programs in LLCCEP assembly language into 
LLCCEP bytecode, which can be executed on emulator, or translated 
to native machine code via JIT/AOT compiler.

# Building the assembler

Build dependencies: C++ compiler, supporting GNU++11 language
standard and CMake util.

1) Generate build reciepe for your IDE/just Makefile

    cmake . -DBUILD_MODE=xxxxxxx;

xxxxxxx is the target type. It may be:
* Debug, to build assembler for debugging
* Release, to build assembler for routine usage
2) Build assembler using your IDE or Make util

The build was tested on the Clang. Building on GCC also occurs
OK, but is not frequently tested, as I prefer using Clang.

# Assembly

The syntax of assembly language is trivial. It was an attempt to build a
more flexible than amd64/i386 assembler, but as simple as ARM's one.
As result, the instruction set is took from ARM, but some
instructions are renamed and their amount is reduced a some.
Call and Jmp instructions syntax is more flexible, than in
amd64/i386 assembler. They just take a condition as a parameter, the
instruction is one.

# Remarks
* Here, and after PC is used as determiner of Program Counter
* sleep(0) means not nothing, but the shortest possible delay

# Instruction set
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
* nop                       | sleep(0) \[Ignored in AOT and JIT compilers\]
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
* call abs                  | call function at $abs
* jmp abs                   | PC := abs
* ret                       | return to the top-level function. If done in \_main, ends program.
* stregs                    | store all registers (may be done multiple times)
* ldregs                    | recover all registers (load last saved results and delete them)

# Conditions 
* al -- Do always
* eq -- Last comparision determined equality of two values
* ne -- Last comparision determined difference of two values
* ae -- Last comparision determined greatness or equality of first value
* le -- Last comparision determined lessness or equality of first value
* ls -- Last comparision determined lessness of first value
* av -- Last comparision determined greatness of first value
Condition is '\@' character followed by condition mnemonic.
Condition can just specify execution requirement in Jmp or Call.

# Registers
There are 32 registers: from 0 to 31.</br>
The determination of register looks like: &id, where id is register id.</br>
Register can specify both destination and source.

# Memory
Memory addressing comes from zero, as traditional.</br>
To specify memory address you need to write: $off, where off is offset from the memory</br>
beginning in memory elements(memory element is a double-percision float-point value).</br>
Memory address can specify both destination and source.

# Numbers
Numbers are double-percision float-point values.</br>
So, they're 8-bytes in length and they are chosen as memory elements.</br>
Numbers can only specify a source.

# Labels
You can place labels everywhere you want. Both before instructions and other labels.</br>
Every label name will be replaced with the address of instruction after it.</br>
So, label name becomes a number, when you place it as an argument.</br>
As the consequence, label name can only specify a source and is translated into number.

# Variables
Since second version, assembler supports variables. They declarations looks like:

    var varName

Assembler substitutes varName, found in code with address in memory of this variable.
