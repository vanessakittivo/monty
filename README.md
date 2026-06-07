Monty
A Monty ByteCode interpreter written in C.
Description
Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack with specific instructions to manipulate it. This project implements an interpreter for Monty bytecode files.
Repository

GitHub repository: monty

Compilation
bashgcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
Usage
bash./monty <file>
Where <file> is the path to a Monty bytecode file.
File Structure
FileDescriptionmonty.hHeader file — structs, typedefs, prototypes, global externsmain.cEntry point, file reading, opcode dispatcher, free_stack0-push_pall.cTask 0 — push and pall opcodes1-pint.cTask 1 — pint opcode2-pop.cTask 2 — pop opcode3-swap.cTask 3 — swap opcode4-add.cTask 4 — add opcode5-nop.cTask 5 — nop opcode6-sub.cTask 6 — sub opcode7-div.cTask 7 — div opcode8-mul.cTask 8 — mul opcode
