# TeachOverflows

This is a collection of buffer overflow challenges intended to be used as a teaching resource. Compile as is or add your own custom flags using 'makeFlag.py', paste the result into the 'SECRET' field in the appropriate file .c file, build them, and have fun.

These programs are intentionally vulnerable and should not be exposed directly to the internet unless the system is meant to be attacked.

## Requirements
- Python 2/3
- Linux with base development tools installed (gcc, make, etc)
- gcc-multilib if compiling on a x64 machine

## Instructions

Clone the repo:

`$ git clone https://github.com/MyBagofTricks/TeachOverflows.git`

Set permissions and run build script: 

`$ cd TeachOverflows && chmod +x build.sh && ./build.sh`

Binaries will be compiled to "bin/". Run each individually and have fun

## The Game

- stack00 - Enter a bunch of letters
- stack01 - Enter the string at the correct offset
- stack02 - Enter the strings at the correct offsets
- stack10 - Same as stack01, but also overwrite the buffer to change the value of the 'changMe' variable
- stack11 - Overflow the buffer and call the 'winner' function
- stack12 - Same as stack11 but with one tiny restriction
- format10 - Overwrite the value of 'changeMe' with 0xCAFEF00D. Payload must be less than 10 chars long (Hint: use printf padding!)
- format11 - Overwrite the value of 'changeMe' with 512
- format12 - Overwrite the value of 'changeMe' with 0xCAFEF00D
- rop10 - Call the 'winner' function with the correct argument
- rop11 - Call 'feedMe2' with the correct arguments, then call 'winner'

## Notes

These programs are broken up into tiers:

- T0 (stack0x): No actual overflows, just easy practices programs
- T1 (stack1x): Simple overflows with stack protectors turned off
- T2 (stack2x): Buffer overflows with shellcode (Coming Soon!)

If compiling manually with gcc, use '-fno-stack-protector -no-pie' for tier 1+

Disable Address Space Layout Randomization to simplify these challenges. Do so by executing this command as root:

`echo 0 > /proc/sys/kernel/randomize_va_space`

## Running on a socket

You can wrap each program in a socket using netcat. nc doesn't seem to play nice, but the ncat which comes with nmap seems fine. 

`ncat -e ./stack1 -lvknp 9999`

    - -e <script>: execute script
    - -lvknp 9999: listen, verbose, keep open (multi handler), nodns, port <9999>

Note: Netcat has some quirks where it may close the in/out pipe before the program closes. Using socat when hosting the files instead of metcat mitigates this issue. You can also see cheatsheet.txt for another workaround.

`socat TCP-LISTEN:3000.reuseaddr,fork EXEC:./stack01`

    - TCP-LISTEN:<port>: port to listen on
    - reuseaddr: bind to a port even if it is being partially used
    - fork: fork the connection. Similar effect to -k in ncat
    - EXEC:<./program>: Program to execute

To beat most of these challenges remotely, attackers will either need a copy of the binaries, or the source and the specifics of the disto used when compiling for the server, so the attacker can compile their own.

## Your "encryption" is bad!
It's only designed to be more effort to reverse than complete the challenge, assuming you include source code. 

## Recommended Reading 
**The Shellcoder's Handbook: Discovering and Exploiting Security Holes**

ISBN-10: 9780470080238 //ISBN-13: 978-0470080238


[Sam Bowne's CNIT 127 Exploit Development Course](https://samsclass.info/) 

Sam's CNIT127 covers the basics well, with hours of videos and projects, all free! If CNIT127 isn't on his front page, check 'Old Classes'


[Smashing The Stack For Fun And Profit](http://www-inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf) When Prometheus gave fire to humanity

