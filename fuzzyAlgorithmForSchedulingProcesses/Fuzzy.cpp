#include<iostream>
#include<cstdlib>


using namespace std;
/*Heres the process I want to do. 
First i will initialize some processes with random numbers between one and ten for their
executionTime, priority, and arrivaltime

Apply for sorting method on arrival time to arrange in ascending
order for (i=1; i<n; i++) 
{ for (j=1; j<n-i; j++) 
if (ATnj>ATnj+1) 
swap 


Compute the frequency of same arrival time and store in x variable.
z=1, AT = ATni, x=1 
for (i=z; a<=n; i++) 
if (ATni == ATni+1) 
AT = ATni, x=x+1, z=z+1 
Else 
AT1 =AT ni+1, z=z+1 
Break

Compare New Priority of all the process which is having arrival time 0 and find Highest Priority (HP).   
HP= NPni  
for (i=1; i<=x; i++) x is frequency of arrival time 0. 
if (NPni < NPni+1)   
HP = NPni+1 
Execute the process which has Highest Priority.

Execute this process until new process will not enter in queue. 
for (i=1; i<AT1-AT; i++) 
Execute P

whenever new process is enter, break executiion of this process
and then again find highest priority among all entered prcesses
after entering all processes in queue apply sorting method on
New priority to arrange in ascending order.

Execute all processes as per assigned priority


 */

const int MAX_PROCESS = 5;
//A process
struct process {
	int executionTime=0;
	int priority=0;
	int arrivalTime=0;
};
 //The maxium number of processes that can exist to processed at a time
process processList[MAX_PROCESS];

int compare(const void * a, const void * b) {
	{
		return (*(int*)a - *(int*)b);
	}
}

/*This class deals with calculating process priority as well has containg the ranges as to which a process can affiliate with a range*/
class priority_calc {
public:
	int new_priority(process);

	int max = 25;
	int veryHigh = 20;
	int high = 15;
	int medium = 10;
	int low = 5;
	int veryLow = 0;
};

/*This class is deals with sorting processes and examining how frequently processes come in at the same time*/


class quick_sort {
public:

	void swap(process*, process*);
	int partition(int, int);
	int random_pivot(int, int);
	void sort(int, int);
	void set_equal(process*,process*);
};

class arrival_time : public quick_sort {
public:

	void same_arrival_freq();
};
void quick_sort::set_equal(process * a, process * b) {
	a->arrivalTime = b->arrivalTime;
	a->executionTime = b->executionTime;
	a->priority = b->priority;
}

void quick_sort::swap(process * a, process * b) {
	process temp;

	
	temp.arrivalTime = a->arrivalTime;
	temp.executionTime = a->executionTime;
	temp.priority = a->priority;

	a->arrivalTime = b->arrivalTime;
	a->executionTime = b->executionTime;
	a->priority = b->priority;

	b->arrivalTime = temp.arrivalTime;
	b->executionTime = temp.executionTime;
	b->priority = temp.priority;

}

int quick_sort::partition(int low, int high) {
	int pivot, index, i;
	index = low;
	pivot = high;

	for (i = low; i < high; i++)
	{
		if (processList[i].arrivalTime < processList[pivot].arrivalTime) {
			swap(&processList[i], &processList[index]);
			index++;
		}
	}
	swap(&processList[pivot], &processList[index]);
	return index;
}

int quick_sort::random_pivot(int low, int high) {
	int pvt, n;
	n = rand();
	pvt = low + n % (high - low + 1);
	swap(&processList[high], &processList[pvt]);

	return partition(low, high);
}

void quick_sort::sort(int low, int high) {
	int pindex;
	if (low < high)
	{
	    pindex = random_pivot(low, high);
		sort(low, pindex - 1);
		sort(pindex + 1, high);
	}
}

/*This is the fuzzy calculation of the priority of a process. Processes that have lower execution times are given higher priority generally.
The calculation of the new priority is based off of two things: the previous priority of the process and the execution time that the process
needs to finish. Calculating the priority is done by assigning a random priority number that exists in the zone where the process belongs 
(verylow,low,medium,high,veryhigh). The numbers are in the range of 0-25 and are split into 5 equal sections where veryhigh is equivilant
to a priority of the range 20-25.*/
int priority_calc::new_priority(process newProcess) {
	if (newProcess.priority < low && newProcess.priority >= veryLow && newProcess.executionTime < low) {
		return newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	if (newProcess.priority < medium && newProcess.priority >= low && newProcess.executionTime < low) {
		return newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	if (newProcess.priority < high && newProcess.priority >= medium && newProcess.executionTime < low) {
		return newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	if (newProcess.priority < veryHigh && newProcess.priority >= high && newProcess.executionTime < low) {
		return newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	if (newProcess.priority <= max && newProcess.priority >= veryHigh && newProcess.executionTime < low) {
		return newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	if (newProcess.priority < low && newProcess.priority >= veryLow && newProcess.executionTime < medium && newProcess.executionTime >= low) {
		return newProcess.priority = (rand() % high - medium + 1) + high;
	}
	if (newProcess.priority < medium && newProcess.priority >= low && newProcess.executionTime < medium && newProcess.executionTime >= low) {
		return newProcess.priority = (rand() % high - medium + 1) + high;
	}
	if (newProcess.priority < high && newProcess.priority >= medium && newProcess.executionTime < medium && newProcess.executionTime >= low) {
		return newProcess.priority = (rand() % veryHigh - high + 1) + veryHigh;
	}
	if (newProcess.priority < veryHigh && newProcess.priority >= high && newProcess.executionTime < medium && newProcess.executionTime >= low) {
		return newProcess.priority = (rand() % veryHigh - high+ 1) + veryHigh;
	}
	if (newProcess.priority <= max && newProcess.priority >= veryHigh && newProcess.executionTime < medium && newProcess.executionTime >= low) {
		return newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	if (newProcess.priority < low && newProcess.priority >= veryLow && newProcess.executionTime < high && newProcess.executionTime >= medium) {
		return newProcess.priority = (rand() % low - veryLow + 1) + low;
	}
	if (newProcess.priority < medium && newProcess.priority >= low && newProcess.executionTime < high && newProcess.executionTime >= medium) {
		return newProcess.priority = (rand() % medium - low + 1) + medium;
	}
	if (newProcess.priority < high && newProcess.priority >= medium && newProcess.executionTime < high && newProcess.executionTime >= medium) {
		return newProcess.priority = (rand() % high - medium + 1) + high;
	}
	if (newProcess.priority < veryHigh && newProcess.priority >= high && newProcess.executionTime < high && newProcess.executionTime >= medium) {
		return newProcess.priority = (rand() % high - medium + 1) + high;
	}
	if (newProcess.priority <= max && newProcess.priority >= veryHigh && newProcess.executionTime < high && newProcess.executionTime >= medium) {
		return newProcess.priority = (rand() % high - medium + 1) + high;
	}
	if (newProcess.priority < low && newProcess.priority >= veryLow && newProcess.executionTime < veryHigh && newProcess.executionTime >= high) {
		return newProcess.priority = (rand() % low - veryLow) + low;
	}
	if (newProcess.priority < medium && newProcess.priority >= low && newProcess.executionTime < veryHigh && newProcess.executionTime >= high) {
		return newProcess.priority = (rand() % low - veryLow) + low;
	}
	if (newProcess.priority < high && newProcess.priority >= medium && newProcess.executionTime < veryHigh && newProcess.executionTime >= high) {
		return newProcess.priority = (rand() % medium - low) + medium;
	}
	if (newProcess.priority < veryHigh && newProcess.priority >= high && newProcess.executionTime < veryHigh && newProcess.executionTime >= high) {
		return newProcess.priority = (rand() % medium - low) + medium;
	}
	if (newProcess.priority <= max && newProcess.priority >= veryHigh && newProcess.executionTime < veryHigh && newProcess.executionTime >= high) {
		return newProcess.priority = (rand() % medium - low) + medium;
	}
	if (newProcess.priority < low && newProcess.priority >= veryLow && newProcess.executionTime < max && newProcess.executionTime >= veryHigh) {
		return newProcess.priority = (rand() % low - veryLow) + low;
	}
	if (newProcess.priority < medium && newProcess.priority >= low && newProcess.executionTime < max && newProcess.executionTime >= veryHigh) {
		return newProcess.priority = (rand() % low - veryLow) + low;
	}
	if (newProcess.priority < high && newProcess.priority >= medium && newProcess.executionTime < max && newProcess.executionTime >= veryHigh) {
		return newProcess.priority = (rand() % low - veryLow) + low;
	}
	if (newProcess.priority < veryHigh && newProcess.priority >= high && newProcess.executionTime < max && newProcess.executionTime >= veryHigh) {
		return newProcess.priority = (rand() % medium - low) + medium;
	}
	if (newProcess.priority <= max && newProcess.priority >= veryHigh && newProcess.executionTime < max && newProcess.executionTime >= veryHigh) {
		return newProcess.priority = (rand() % medium - low) + medium;
	}

	return -1;

}


//Calculating the frequency at which a process can
void arrival_time::same_arrival_freq() {

}


int main() {
	priority_calc obj;
	process test1,test2,test3,test4,test5;
	arrival_time thing;
	
	
	test1.arrivalTime = 2;
	test2.arrivalTime = 4;
	test3.arrivalTime = 3;
	test4.arrivalTime = 1;
	test5.arrivalTime = 5;
	
	processList[0] = test1;
	processList[1] = test2;
	processList[2] = test3;
	processList[3] = test4;
	processList[4] = test5;

	
	thing.sort(0, 4);
	

	for (int i = 0; i < 5; i++) {
		cout << processList[i].arrivalTime;
	}
	

}