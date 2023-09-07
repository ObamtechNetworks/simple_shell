# 0x16. C - Simple Shell (PROJECT)
> To write a simple UNIX command interpreter
## ALX SE Team/Collaboration Project
## Background Information
> *Welcome to the Simple Shell Documentation Project!*
> Project is a 10 weight point as provided and mandated for all ALX Software Engineering Student.

It is a collaborative project involving a team of two and I am so fortunate to have been a partner of this project with:
- [Gideon Edoghotu](https://github.com/giddy11)
This project is an educational project of course as it challenges us about everything you have learn so far at ALX SE:
- Basics of programming
- Basics of C
- Basics of thinking like an engineer
- Group work
- and Learning how to learn

# RESOURCES GIVEN BY ALX
- [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
- [Everything you need to know to start coding your own shell concept page]

**man or help:**
- sh (Run sh as well)

# FOCUSED LEARNING OBJECTIVES (BY ALX)
## General
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

# LIST OF ALLOWED FUNCTIONS WE WERE CONSTRAINED WITH
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

# AUTHORS FOR THIS REPO/PROJECT
- [Ipadeola Bamidele Michael](https://github.com/ObamtechNetworks)
- [Gideon Edoghotu](https://github.com/giddy11)

# ALX PROJECT REQUIREMENTS
# General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/alx-tools/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/alx-tools/Betty/blob/master/betty-doc.pl)
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)
Write a README with the description of your project
You should have an *AUTHORS* file at the root of your repository, listing all individuals having contributed content to the repository. 
Format, see [Docker](https://github.com/moby/moby/blob/master/AUTHORS)

# CONSTRAINTS ON GitHub
*There should be one project repository per group. If you and your partner have a repository with the same name in both your accounts, you risk a 0% score. Add your partner as a collaborator.*

# CHECKS (CONSTRAINTS)
The Checker will be released at the end of the project (1-2 days before the deadline).
We were constrained to keep working and testing by ourselves, without the checker being released until 1-2 days of the first deadline!

# COMPILATION
ALX SE: Your shell will be compiled this way:
``gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh``

# TESTING
ALX: Your shell should work like this in interactive mode:
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

ALX: But also in non-interactive mode:
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
