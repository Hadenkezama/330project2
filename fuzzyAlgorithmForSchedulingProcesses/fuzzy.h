#pragma once
/*Haden Remoue-Kezama
200379095

This program is a fuzzy schedular for processes. It first sorts by arrival time and then sorts by the priority of a processes. When a new process is 
added to the queue, calculate a new priority for each process based on execution time and previous priority. Then resort, all the processes in the 
queue.

Limitations: There is minimal error checking in this program. It needs to be fine tuned.*/
#include<iostream>
#include<cstdlib>
#include <time.h>
#include <Windows.h>
#include <string>

using namespace std;
//Maximum number of processes in the queue
const int MAX_PROCESS = 5;

// A process
struct process {
	int executionTime = 0;
	int priority = 0;
	int arrivalTime = 0;
	int id = 0;
};



//used for sorting the processes by arrival time and by priority
class quick_sort {
public:

	void swap(process*, process*);
	int arrival_partition(int, int, process[]);
	int priority_partition(int, int, process[]);
	int priority_pivot(int, int, process[]);
	int arrival_pivot(int, int, process[]);
	void priority_sort(int, int, process[]);
	void arrival_sort(int, int, process[]);
};

//class for implementing the queue
class queue {
public:
	process *arr;
	int capacity;
	int front;
	int rear;
	int count;


	queue(int size = MAX_PROCESS);
	~queue();

	void dequeue();
	void enqueue(process);
	int size();
	bool is_empty();
	bool is_full();
};



/*This class deals with calculating process priority. It also executes the processes and calculates how many processes arrive at the same time*/
class priority_calc {
public:
	void new_priority(process&);
	void execute(queue&);
	void highest_priority_calc(process[],int);
	int same_arrival_freq(int, process[]);
	int max = 25;
	int veryHigh = 20;
	int high = 15;
	int medium = 10;
	int low = 5;
	int veryLow = 0;
};






