# COMPSCI 377
# Scheduling Lab

## Purpose

This lab is designed to cover different types of scheduling used in operating systems, such as Round Robin. Please make sure that all of your answers to questions in these labs come from work done on the Edlab environment – otherwise, they may be inconsistent results and will not receive points.

Please submit your answers to this lab on Gradescope in the assignment marked “Lab #4’. All answers are due by the time specified on Gradescope. The TA present in your lab will do a brief explanation of the various parts of this lab, but you are expected to answer all questions by yourself. Please raise your hand if you have any questions during the lab section – TAs will be notified you are asking a question. Questions and Parts have a number of points marked next to them to signify their weight in this lab’s final grade. Labs are weighted equally, regardless of their total points.

All code compiled and run in these labs should be done on Edlab, otherwise results may not be consistent with the answer key.

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
```
#include <iostream>
#include <queue>

using namespace std;

struct Bird {
	float size;
	
	Bird(float size2){
		size = size2;
	}
};

struct SizeCheck{
	bool operator()(Bird const& b1, Bird const& b2){
		return b1.size < b2.size;
	}
};

int main() {
	priority_queue<int> numbers; //This is a simple priority queue of numbers
	numbers.push(5);
	numbers.push(10);
	numbers.push(99);
	numbers.push(60);
	numbers.push(94);
	while (!numbers.empty()){
		cout << numbers.top() << "\n"; //Prints out the order of 99, 94, 60, 10, 5
		numbers.pop();
	}
	cout << "\n";
	
	priority_queue<Bird, vector<Bird>, SizeCheck> birds; //Uses the Bird struct, a vector of type Bird, and the SizeCheck operator to compare Birds
	birds.push(Bird(30));
	birds.push(Bird(3));
	birds.push(Bird(8));
	birds.push(Bird(12));
	birds.push(Bird(35));
	while (!birds.empty()){
		Bird b = birds.top();
		birds.pop();
		cout << b.size << "\n"; //Prints out the order of 35, 30, 12, 8, 3
	}
	cout << "\n";


	return 0;
}
```

The code above creates two priority queues, called numbers and birds. Each sorts from high to low its metric – for numbers, the element itself, and for Birds their size. As can be seen, it is significantly more difficult to sort a priority queue based on a struct than a primitive data type. There are also methods that can be done to create priority queues using classes – it is encouraged to look these up as they might be useful, but not required.

Additionally, it is good to remember three major methods when working with priority queues: push, top, and pop. push allows you to add an element to the priority queue, top returns the element at the front of the queue, and pop removes the front element of the queue. You can also use the empty and size methods to return whether the queue is empty or its size, respectively.

## Part 2: FIFO (3 Points):
One scheduling algorithm is FIFO, or First In First Out. As it sounds, the scheduling algorithm simply runs whichever processes arrive first, and finishes with whichever processes arrive last. In essence, it acts like a line at the grocery store, taking whichever customer arrives first. While this does grant every process hypothetical fastest time, in reality a very slow process could bog down the system like a grocer with too much produce. If that happens, faster processes like a customer with only 10 items or less could be forced to wait even though they could be done in a short period of time.

## Part 3: SJF (3 Points):
The grocer with 10 items or less complained to the manager about their FIFO policy, and the store has now changed to the SJF policy, or Shortest Job First. With this new policy, the scheduling algorithm runs whichever process is the shortest, and finishes with whichever process is the longest. In the supermarket, this means that if someone has a lot of produce and is taking a while to check out, the cashier will tell them to wait and checks out someone with only a few items first. This leads to its own problem, however, in that the new policy only checks for shoppers that are all in line at the same time – if someone with a lot of groceries arrives before everyone else, they still have to wait for the one shopper to finish.

## Part 4: STCF (3 Points):
Shoppers are still complaining that they have to wait too long in line, and the manager is getting upset. They implement a new policy called STCF, or Shortest Time to Completion First. This new policy is similar to SJF, except that it will interrupt any shopper with a lot of groceries to quickly check out shoppers with only a few groceries. It will overall prioritize the shoppers who have the least amount of time left to check out – for example, a person with a lot of groceries that has mostly checked out would be prioritized over someone that has not been checked out and that has half their groceries. However, this policy still forces long processes to wait for the processes in front of them to finish if they have not yet started.

## Part 5: RR (3 Points):
Finally, the manager has had enough. Customers keep complaining, and they have no idea how to stop it. For their final act, they implement the RR policy, which dictates that customers be partial checked out one after enough, looping through the line over and over again until everyone is checked out. This policy means that shoppers will all receive attention one at a time, but may take a while to finish if there are many customers in line.

However, Round Robin requires that processes be attended to for a while before moving onto the next one – otherwise, the cost of switching between processes becomes large enough that it fails to save any time at all. Additionally, while processes all get attention from the CPU relatively soon, it is terrible in turnaround time, since it must slowly iterate through all of the processes until it finishes.
