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
<http://cat.pdx.edu/weblinks/tutors/gdb-quick-reference-sheet.html>

* For a different interface: `gdbtui`

