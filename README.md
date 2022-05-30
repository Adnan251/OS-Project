# OS-Project

~~~~~MEMBER NAMES:
  Adnan Džindo
	Ilma Džaferović

~~~~~LIST OF FILES:
	Shell.c     ---> holds all the code for the shell
	copycat.c   ---> used for a special function in the shell

~~~~~ASSIGNMENT QUESTION ANSWERS:
	Q1: The following actions, do they require the OS to use kernel mode or user mode is sufficient?
		* When starting a process OS is required to use kernal mode because every proces is started 
		  with a EXEC() system call, and we have learned before that system calls are ways we interact
		  with the kernel.
		* Because the multiplication isdone in the applications memory there is no need for the kernel mode.
		* Because the system needs to access the hardware to write to a file we will need to use the kernal mode.
		  This is because all usess of Hardware components are done through the kernel. 

	Q2: Explain the purpose of a system call. Describe how control passes to the kernel when
	    executing a system call.
		* A system call is a mechanism that provides the interface between a process and the operating system. 
		  It is a programmatic method in which a computer program requests a service from the kernel of the OS.
		  System call offers the services of the operating system to the user programs via API (Application 
		  Programming Interface). System calls are the only entry points for the kernel system.
		  In order to execute a system call a program needs to execute a special trap instruction. This instruction
		  accesses the kernel and switches the mode to kernel mode. The code which the trap runs is stored inside a 
		  trap table which the kernel sets up at boot time. In the kernel, the system can perform any privileged 
		  operations which are needed and do the required work for the calling process. On completion, 
  		  the operating system calls a return-from-trap instruction which returns into the program, switches to user 
		  mode and begins running the process.

~~~~~OUTLINE:
	Our tas was to design and implement a basic shell interface that supports the execution of other programs and a
	series of built-in functions. We have managed to do most of the tasks except creating a pipe and implementing 
	vfork() and exec() system calls. 
	
	            ~~~~~HELP~~~~~

        Function      |   Tag   |       Description	
--------------------------------------------------------------------------------------------------------
        mkdir_s       |         |   This function creates a directory if it already odesnt exits       
                      |   -h    |   Show the help page
--------------------------------------------------------------------------------------------------------
        uptime        |         |   Tells how long the system has been running      
                      |-p1, -p2 |   shows the time in different way
                      |   -h    |   Show the help page
--------------------------------------------------------------------------------------------------------
          ls          |         |   List FILEs in current directory       
                      |   -h    |   Show the help page
                      |   -c    |   Gives color to the output
--------------------------------------------------------------------------------------------------------
          sl          |         |   Prints oput a boat that moves across the screen       
--------------------------------------------------------------------------------------------------------
        mything       |         |   A function that uses a fork(), wait() and exec() system calls       
--------------------------------------------------------------------------------------------------------
      sleepycat       |         |   This function wakes up the cat, she is very grupy be aware if you 
                      |         |   anger the cat she will crash your pc (Use a ForkBOMB)      
--------------------------------------------------------------------------------------------------------

~~~~~COMPILING INSTRUCTIONS:
	gcc -Wall -o shell shell.c

	gcc -Wall -o copycat copycat.c

	./shell


~~~~~CHALLENGES INCOUNTERED:
	There were a few challenges that we have incountered during this project. But the main one we will focus in is
	the fact that there are not many quality examples or vides on this topic. Dont get us wrong there are videos on
	youtube but most of them are very porely made or in some cases, they are made in a language that is not familiar
	to us.
	Apart from this problem there were not many more big problems. When we figured out what we needed to do and what 
	was expected from us everything went smoothly.


~~~~~MATERIAL USED:
	https://stackoverflow.com/questions/38796808/how-to-safely-try-out-a-fork-bomb
	https://www.linuxtechi.com/learn-use-fork-vfork-wait-exec-system-calls-linux/
	https://www.theurbanpenguin.com/4184-2/
	https://www.systutorials.com/how-to-get-the-hostname-of-the-node-in-c/
	https://www.youtube.com/watch?v=j9yL30R6npk
	https://www.youtube.com/watch?v=OVFEWSP7n8c
 	https://www.youtube.com/watch?v=k6TTj4C0LF0
	https://www.youtube.com/watch?v=cNBrsrvxeQg
	https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
