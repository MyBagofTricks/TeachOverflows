# TeachOverflows

This is a collection of buffer overflow challenges intended to be used as a teaching resource. Compile as is or add your own custom flags using 'makeFlag.py', and paste the result into the 'SECRET' field in the appropriate file .c file.

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

Binaries will be compiled to "overflows/". Run each individually and have fun

## Notes

These programs are broken up into tiers:

- T0 (stack0x): No actual overflows, just easy practices programs
- T1 (stack1x): Simple overflows with stack protectors turned off
- T2 (stack2x): Buffer overflows with shellcode (WIP)

So far there are standard stack overflow and return orientated programming challenges. Format string vulnerabilities and more rops will be added shortly.

If compiling manually with gcc, use '-fno-stack-protector -no-pie' for tier 1+

Address Space Layout Randomization should be disabled for tier1+. Execute this command as root:

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



## Your 'encryption' is bad!
It's only designed to be more effort to reverse than complete the challenge, assuming you include source code. 

## Recommended Reading 
**The Shellcoder's Handbook: Discovering and Exploiting Security Holes**

ISBN-10: 9780470080238 //ISBN-13: 978-0470080238


[Sam Bowne's CNIT 127 Exploit Development Course](https://samsclass.info/) 

Sam's CNIT127 covers the basics well, with hours of videos and projects, all free! If CNIT127 isn't on his front page, check 'Old Classes'


[Smashing The Stack For Fun And Profit](http://www-inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf) When Prometheus gave fire to humanity

