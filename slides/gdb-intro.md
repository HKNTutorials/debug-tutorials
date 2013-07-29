layout: false
# Debugging
- First approach: print everything
- Better way: **gdb**
  - Interactive
  - Inspect variables
  - See current stack

???
While debugging is the focus of these tutorials, *testing* is actually more
fundamental to writing correct programs. Writing tests will expose your
problems to the point where you can begin to debug.

Once you have an idea of where something is wrong in your program you'll want
to figure out what went wrong. GDB shines here by giving you a way to
interactively control and inspect your program. You chose where you want to
stop the program (*breakpoints*). From there you can print out variables,
continue the program (either by *stepping*, or advancing line-by-line, or
continuing until the next breakpoint), or set more breakpoints. This
interactivity is enormously powerful in letting you find bugs in as few
iterations as possible.

Taking advantage of GDB only requires learning how to use it: in particular, no
changes to your programs are needed. In addition, you'll be able to apply these
same skills to C++ and assembly programs.

---

# Getting started with GDB
First, you must compile and link your program with debug symbols

- Use `-g` flag (for both `gcc` and `clang`)
- `Makefile` should include this
  - ours do
  - yours should too!
- Start `gdb` with your program loaded:
      gdb ./my_program

???
- The `-g` flag is recommended and used by course staff to make debugging with
`gdb` (and other debuggers) possible.
- We recommend you use a Makefile for a few reasons:
  - It documents how to compile the program
  - It makes compiling easy, which means you'll do it more often
  - You'll remember to use all the options you're supposed to (`-g`, `-Wall`,
    `-Werror`) every time

---

# GDB Commands
- `help`

        (gdb) help
        List of classes of commands:

        aliases -- Aliases of other commands
        breakpoints -- Making program stop at certain points
        data -- Examining data
        files -- Specifying and examining files
        internals -- Maintenance commands
        obscure -- Obscure features
        running -- Running the program
        stack -- Examining the stack
        status -- Status inquiries
        support -- Support facilities
        tracepoints -- Tracing of program execution without stopping the program
        user-defined -- User-defined commands

        Type "help" followed by a class name for a list of commands in that class.
        Type "help" followed by command name for full documentation.
        Command name abbreviations are allowed if unambiguous.
        (gdb)

???

Seriously, this is the most useful command in GDB.

---

# GDB Commands
## Controlling the program
- `break [function or line number]` sets a *breakpoint*
- `run` starts running your program
- `step` and `next` continues till the next program line
  - `step` will enter functions
  - `next` will skip over them
- `continue` continues until the program exits

???

The main step in using GDB is to set breakpoints, points in your program where
GDB will stop and let you enter more commands. There are lots of commands for
working with breakpoints: you can disable them temporarily, have them trigger
after they've been hit a certain number of times, and even make them
conditional on some arbitrary code. To find out more, start with `help
breakpoints` from within GDB. From there you can read the
[documentation](http://sourceware.org/gdb/current/onlinedocs/gdb/Breakpoints.html#Breakpoints)
for more details.

---

# GDB Commands
## Inspection in GDB
- `list` shows the source code around where you currently are
- `print [variable]` will print the current value of a variable in your program
- `display [variable]` like `print`, but prints the variable after every
  command
- `backtrace` displays the sequence of function calls leading to the current
  point

???

Here are a few of the additional commands we use most frequently:

- There are short forms of many of the above such as:
  - `b` for `break`
  - `p` for `print`
  - `s` for `step`
  - `n` for `next`
- An empty line runs the last command (useful for stepping)
- `info breakpoints` gives a list of breakpoints and their numbers
- `info display` does the same for displayed variables
- `delete [num]` deletes breakpoints and `undisplay [num]` stops displaying a
  variable
