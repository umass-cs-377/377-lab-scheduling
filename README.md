# COMPSCI 377 LAB #4: Scheduling

## Purpose

This lab is designed to cover different types of scheduling used in operating systems, such as Round Robin. Please make sure that all of your answers to questions in these labs come from work done on the Edlab environment – otherwise, they may be inconsistent results and will not receive points.

Please submit your answers to this lab on Gradescope in the assignment marked “Lab #4’. All answers are due by the time specified on Gradescope. The TA present in your lab will do a brief explanation of the various parts of this lab, but you are expected to answer all questions by yourself. Please raise your hand if you have any questions during the lab section – TAs will be notified you are asking a question. Questions and Parts have a number of points marked next to them to signify their weight in this lab’s final grade. Labs are weighted equally, regardless of their total points.

Once you have logged in to Edlab, you can clone this repo using

```bash
git clone https://github.com/umass-cs-377/377-lab-scheduling.git
```

Then you can use `cd` to open the directory you just cloned:

```bash
cd 377-lab-scheduling
```

This repo includes a Makefile that allows you to locally compile and run all the sample code listed in this tutorial. You can compile them by running `make`. Feel free to modify the source files yourself, after making changes you can run `make` again to build new binaries from your modified files. You can also use `make clean` to remove all the built files, this command is usually used when something went wrong during the compilation so that you can start fresh.

## Part 1: Priority Queues (5 Points)
Priority queues can be a very useful tool in making various programs, and especially so in creating scheduling algorithms. They work just like queues, but instead of adding in new elements at the end elements are added with some value attached to them, and enter the queue such that it is sorted by the values of its elements. This means we can do things like create priority queues that prioritize certain elements, and push back other kinds of elements. As an example, please look at the code below:

bird.cpp
