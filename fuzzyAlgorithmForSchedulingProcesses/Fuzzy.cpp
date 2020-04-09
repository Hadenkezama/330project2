#include "fuzzy.h"


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



int quick_sort::arrival_partition(int low, int high, process list[]) {
	int pivot, index, i;
	index = low;
	pivot = high;

	for (i = low; i < high; i++)
	{
		if (list[i].arrivalTime < list[pivot].arrivalTime) {
			swap(&list[i], &list[index]);
			index++;
		}
	}
	swap(&list[pivot], &list[index]);
	return index;
}

int quick_sort::priority_partition(int low, int high, process list[]) {
	int pivot, index, i;
	index = low;
	pivot = high;

	for (i = low; i < high; i++)
	{
		if (list[i].priority < list[pivot].priority) {
			swap(&list[i], &list[index]);
			index++;
		}
	}
	swap(&list[pivot], &list[index]);
	return index;
}

int quick_sort::priority_pivot(int low, int high, process list[]) {
	int pvt, n;
	n = rand();
	pvt = low + n % (high - low + 1);
	swap(&list[high], &list[pvt]);

	return priority_partition(low, high);
}

int quick_sort::arrival_pivot(int low, int high, process list[]) {
	int pvt, n;
	n = rand();
	pvt = low + n % (high - low + 1);
	swap(&list[high], &list[pvt]);

	return arrival_partition(low, high);
}

void quick_sort::arrival_sort(int low, int high, process list[]) {
	int pindex;
	if (low < high)
	{
	    pindex = arrival_pivot(low, high,list);
		arrival_sort(low, pindex - 1,list);
		arrival_sort(pindex + 1, high,list);
	}
}

void quick_sort::priority_sort(int low, int high, process list[]) {
	int pindex;
	if (low < high)
	{
		pindex = priority_pivot(low, high,list);
		priority_sort(low, pindex - 1,list);
		priority_sort(pindex + 1, high,list);
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
int arrival_time::same_arrival_freq(int min, process list[]) {
	
			
	while (list[min].arrivalTime == list[min + 1].arrivalTime) {
			min++;
		}
			min++;

	return min;

}

void priority_calc::highest_priority_calc_execute(process list[]) {
	int i, x = 0;
	arrival_time obj;
	arrival_sort(0, 4,list);
	
	x = obj.same_arrival_freq(x,list);

	process *temp = new process[x];

	priority_sort(0, x,list);


		 while (i < MAX_PROCESS){
			cout << "Executing process id: " << list[i].id << endl;
			cout << "Process execution time remaining: " << list[i].executionTime << endl;
			Sleep(1000);
			list[i].executionTime--;

			if (list[i].executionTime == 0) {
				i++;
			}
		}
		
	
}


