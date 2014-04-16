Make, GDB, and Valgrind
=======================

Wed, Jan 15 2014
Thu, Jan 16 2014

Kendall Stewart
kendall@cat.pdx.edu

Overview
--------

* What are these programs? Why lump them together?
  - They are all commonplace tools that will
    make your life as a programmer easier.
  - Emphasis on "tools" - just more things to add
    to your programmer's toolbox. 
  - Whether you use them or not depends on the situation.

* Make:
  - Very powerful tool (and scripting language) for building 
    and configuring software
  - Essential for managing even modestly complex projects
  - But good for small projects, too:
    - No more `g++ -g -Wall *.cpp` over and over
    - No more recompiling files you haven't changed

* GDB:
  - Interactive debugging tool
  - Allows you to trace execution line-by-line to investigate
    your program's behavior and find errors (like segmentation faults,
    bad output, etc)
  - Supplements your diagnostic reasoning, doesn't replace it!

* Valgrind:
  - Memory checking tool
  - Only available on linuxlab machines (not on chandra)
  - Most common use: finding memory leaks with --leak-check=full

* A caveat:
  - I am by no means an expert in using these tools!
  - That's okay, since we only have time for a basic overview anyway.
  - If you want to know more, read the man page! Play with the tools! 
    - You (probably) won't break anything.
    - (Better safe than sorry. Make a backup before you accidentally
       drill a hole through your program).

Setup
-----
* Open a new terminal (ctrl-alt-T)
* Type the following command into your terminal:
    git clone https://github.com/pdx-cstutors/workshops.git

