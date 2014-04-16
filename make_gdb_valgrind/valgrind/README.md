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


