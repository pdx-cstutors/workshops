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
  - By convention, variable names are IN\_ALL\_CAPS
  - Their values are strings, but you don't need quotes around them.
  - To set a variable, use the syntax `VAR = string`
  - To expand (use) a variable, use the syntax `$(VAR)`

* Makefiles can get pretty complex... 
<http://www.gnu.org/software/make/manual/html_node/Complex-Makefile.html>

* That is to say, there's a lot more out there.

