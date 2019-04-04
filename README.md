# TeachOverflows

This is a collection of buffer overflow challenges intended to 
demonstrate and teach the basic concepts. Compile as-is or add 
your own custom flags by updating flags.txt in the scripts folder
and running 'makeflags.sh'.

These programs are intentionally vulnerable and should not be exposed 
directly to the internet unless the system is meant to be attacked.

## Requirements
- Python 2/3 (for custom flags)
- Linux with base development tools installed (gcc, make, etc)
- gcc-multilib if compiling on a x64 machine

## Instructions

Clone the repo:

`$ git clone https://github.com/MyBagofTricks/TeachOverflows.git`

### Using make

`make` 

### Using Docker

`docker build -t teach . && docker run -p 80:80 -p 3010-3021:3010-3021 -it teach`

## The Game

| Level     |   Type   |   Hint    |
| ----------| ---------|-----------|
| level01   | Practice | Enter 60 characters |
| level02   | PRACTICE | Enter the string at the correct offset |
| level03   | PRACTICE | Enter the strings at the correct offsets |
| level04   | BOF      | Enter the string, and overwrite the variable |
| level05   | BOF      | Overflow the buffer and call winner() |
| level06   | BOF      | Overflow the buffer and call winner() |
| level07   | FORMAT   | Overwrite the variable with the string, using less than 10 chars |
| level08   | FORMAT   | Overwrite the variable with 512 |
| level09   | FORMAT   | Overwrite the variable with 0xCAFEF00D |
| level10   | ROP      | Call the function with the correct argument |
| level11   | ROP      | Call the first function with the correct arguments, then call 'winner' |
| level12   | HEAP     | Just like a buffer overflow |

## Notes

If compiling manually with gcc, use '-fno-stack-protector -no-pie' to
disable Address Space Layout Randomization and stack protections. Disabling
globally is also recommended when targeting libc.

Do so by executing this command as root:

`echo 0 > /proc/sys/kernel/randomize_va_space`

## Running on a socket

You can wrap each program in a socket using netcat. nc doesn't seem 
to play nice, but the ncat which comes with nmap seems fine. 
```
ncat -e ./level01 -lvknp 9999`

    - -e <script>: execute script
    - -lvknp 9999: listen, verbose, keep open (multi handler), nodns, port <9999>
```
Note: Netcat has some quirks where it may close the in/out pipe before the 
program closes. Using socat when hosting the files instead of metcat 
mitigates this issue. You can also see cheatsheet.txt for another workaround.
```
socat TCP-LISTEN:3000.reuseaddr,fork EXEC:./level01`

    - TCP-LISTEN:<port>: port to listen on
    - reuseaddr: bind to a port even if it is being partially used
    - fork: fork the connection. Similar effect to -k in ncat
    - EXEC:<./program>: Program to execute
```
To beat most of these challenges remotely, attackers will either need a 
copy of the binaries, or the source and the specifics of the disto 
used when compiling for the server, so the attacker can compile 
their own.

## Your "encryption" is bad!
Correct. Reversing it should be some easy homework.

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
