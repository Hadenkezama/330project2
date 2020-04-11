#pragma once
#include<iostream>
#include<cstdlib>
#include <time.h>
#include <Windows.h>
#include <string>

using namespace std;

const int MAX_PROCESS = 5;

// A process
struct process {
	int executionTime = 0;
	int priority = 0;
	int arrivalTime = 0;
	int id = 0;
};
//The maxium number of processes that can exist to processed at a time



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
	process peek();
	int size();
	bool is_empty();
	bool is_full();
};



/*This class deals with calculating process priority as well has containg the ranges as to which a process can affiliate with a range*/
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

/*This class is deals with sorting processes and examining how frequently processes come in at the same time*/




