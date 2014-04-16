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
    tar -xvf /stash/tutors/workshops/mgv.tar

Make
----
* In the terminal:
    cd mgv/make/prog1
    ls

* Open 'main.cpp' in (vim|emacs|nano|ed|your-favorite-text-editor)
  - Nothing magic here!

* Open the file called 'makefile'
  - 'makefile' (or 'Makefile') is a special file, with a special name
  - it is the file read when you execute the command 'make' in
    a given direcotry

* Makefiles have special syntax and structure:

target: [dependencies]
	[commands]

  - target: the label for the command to be executed
    -- execute `make <target name>` to build a specific target
    -- 'all' is a special target that is built when make
       is invoked with no arguments

  - dependencies: the files that must be present and up-to-date
                  before this target can be built

  - commands: the commands to be executed to build this target
    - Not necessairly a compile command; in fact can be any commands
    - Most makefiles have a target called "clean" (not a special name,
      but a standard convention) that removes intermediate files with `rm`.
    - Can have multiple commands on separate lines


* NOTA BENE: the command must be indented by a hard tab! Not spaces!
  - This can pose problems if you have tabs turned off in your
    editor (and you *should* have tabs turned off in your editor).
  - To insert a hard tab in vim/emacs, use a "quote" command:
    -- In vim: Ctrl-V TAB
    -- In emacs: Ctrl-Q TAB
  - In nano, use ESC-Q to switch between tabs/spaces mode

* Now:
  cd ../prog2

* Program 2:
  - This example features multiple targets and conditional compilation
  - A target is only recompiled if a file it depends on has changed!
  - Notice that on the first `make`, both main.cpp and hello.cpp are compiled
  - Now let's change just hello.cpp and type `make` again

* Program 3:
  - Variables!
  - You can set variables in make. They are handy for setting project-wide
    flags, like turning debugger symbols on and off (-g)
  - By convention, variable names are IN_ALL_CAPS
  - Their values are strings, but you don't need quotes around them.
  - To set a variable, use the syntax `VAR = string`
  - To expand (use) a variable, use the syntax `$(VAR)`

* Makefiles can get pretty complex... 
http://www.gnu.org/software/make/manual/html_node/Complex-Makefile.html

* That is to say, there's a lot more out there.

GDB
---
* Now:
  cd ../../gdb/prog1

* A little intro:
  - To run a program in gdb:
    gdb ./a.out
    # A bunch of text, NO WARRANTY blah bloo blee #
    (gdb) run

  - If you want nice things like line numbers and variable names,
    your program MUST be compiled with -g! 
  - Of course, now that you are a makefile expert, this should be easy.

* Program 1: Segfault hunting.
  - What's wrong with this program?
  - GDB can help us find out.
  - Load and execute and...
  - SIGSEGV ... at main.cpp:10
  - How nice!
  - type `list` to see the surrounding code

* Program 2: Stack tracing.
  - Sometimes we want to see the chain of events that led to a crash.
  - Load with gdb and execute and...
  - SIGSEGV in dootherthings
  - Type `backtrace` or `bt`
  - This provides a list of all function calls currently on the stack
  - Navigate the stack with `up` and `down`
  - Print out useful information with `info locals` and `info args`

* Program 3: Breakpoints and watchpoints.
  - What's going on in this program? Do you see the error?
  - Lets try this:
    `break main`
    `run`
    `watch i`
    `continue`

* Program 4: Poking around in data structures.
  - This program inputs a series of values into a binary search tree,
    but something's not quite right - they're printing in reverse order.

  - We know what it's supposed to do, but the problem could
    either be in the insert or the display! We need to diagnose which.

  - We know what the structure's supposed to look like...
    - But how can we verify it?

  - Set a breakpoint after the data has all been input.
  - Use the `print` command

  - Notes on `print`:
    - Can access private class data
    - Can chase pointers with . operator instead of ->
    - Can dereference pointers with *
    - Can index arrays with []

* Some thoughts:
  - GDB is a tool for assisting YOU in diagnosis...
    not doing the diagnosis for you.
  - Once you find the cause of the error (the mistake you made),
    think about the cause of the mistake!
    - This is the true goal of debugging: root cause analysis.    
    - What could you do to avoid making that mistake again?
      - Better variable names?
      - Better abstraction?
      - More thoughtful design?

* GDB has hundreds of commands:
http://cat.pdx.edu/weblinks/tutors/gdb-quick-reference-sheet.html

* For a different interface: `gdbtui`

Valgrind
--------
* Memory analyzer, and so much more.
  - This program has a LOT of functionality; see `man valgrind`
  - We're just going to be using it to check for memory leaks,
    and getting more information about segfaults.

* Program 1: Segfault information.
  - This looks familiar... same as gdb/prog1
  - Run with `valgrind ./a.out`
  - Unlike gdb, program begins executing automatically
  - Valgrind will tell you why you got a segfault:
    - In this case, "Invalid read"

* Program 2: Checking for memory leaks.
  - This program is simple enough...
  - If we run it, there are no error messages.
  - But what's wrong with this picture?
  - Let's push it through valgrind...
  - "Rerun with --leak-check=full to see details of leaked memory"
  - "--leak-check" is a command line option, "full" is its parameter
  - `valgrind --leak-check=full ./a.out`
  - Can see the line number that caused a memory leak!

* Let's try running it on our tree example from earlier...

* Some thoughts...
  - It's probably a good idea to run ALL of your C/C++ programs
    through valgrind periodically.
  - Don't just ignore memory leaks! Try and track them down and fix them.
  - Memory leaks are often indicative of other bugs!
  - As above, try and figure out the root cause of your mistake.
  - Re-evaluate your design process, if necessary.


