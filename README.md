# TeachOverflows

This is a collection of buffer overflow challenges intended to 
demonstrate the basic concepts. Compile as-is or add your own 
custom flags by updating flags.txt in the scripts folder
and running 'scripts/makeflags.sh'.

These programs are intentionally vulnerable and should not be exposed 
directly to a network the intention is to have them attacked.

## Requirements
- Python
- Linux with base development tools installed (gcc, make, etc)
- gcc-multilib if compiling on a x64 machine
- optional: docker

## Instructions

Clone the repo:

`$ git clone https://github.com/MyBagofTricks/TeachOverflows.git`

### Using make

`make` 

### Using Docker

`docker build -t teach . && docker run -p 80:80 --hostname=TeachOverFlows -p2222:22 -it teach`

## The Game

| Level     |   Type   |   Hint    |
| ----------| ---------|-----------|
| level01   | Practice | Enter 60 characters |
| level02   | Practice | Enter the string at the correct offset |
| level03   | Practice | Enter the strings at the correct offsets |
| level04   | BOF      | Enter the string, and overwrite the variable |
| level05   | BOF      | Overflow the buffer and call winner() |
| level06   | BOF      | Overflow the buffer and call winner() |
| level07   | Format   | Overwrite the variable with the string, using less than 10 chars |
| level08   | Format   | Overwrite the variable with 512 |
| level09   | Format   | Overwrite the variable with 0xCAFEF00D |
| level10   | ROP      | Call the function with the correct argument |
| level11   | ROP      | Call the first function with the correct arguments, then call 'winner' |
| level12   | Heap     | Just like a buffer overflow |

## Notes

If compiling challenges manually with gcc, use '-fno-stack-protector -no-pie' to
disable Address Space Layout Randomization and stack protections. Disabling
globally can be done to simplify attacks on libc.

Execute as root to disable ASLR globally:

`echo 0 > /proc/sys/kernel/randomize_va_space`


## Your "encryption" is bad!
Correct. Reversing it should be easy homework.

## Recommended Reading and Acknowledgements
**The Shellcoder's Handbook: Discovering and Exploiting Security Holes**

ISBN-10: 9780470080238 //ISBN-13: 978-0470080238


[Sam Bowne's CNIT 127 Exploit Development Course](https://samsclass.info/) 
- Sam's CNIT127 covers the basics well, with hours of videos and 
projects, all free! If CNIT127 isn't on his front page, check 'Old Classes'


[Smashing The Stack For Fun And Profit](http://www-inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf)
- When Prometheus gave fire to humanity


[Protostar CTF](https://www.vulnhub.com/entry/exploit-exercises-protostar-v2,32/)
- The basic progression of challenges were inspired by Protostar, and 
it remains a solid tool for learning overflows with a limited toolset.
