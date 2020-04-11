
#include "fuzzy.h"
//Compare two integer values
int compare(const void * a, const void * b) {
	{
		return (*(int*)a - *(int*)b);
	}
}

//Swap two processes
void quick_sort::swap(process * a, process * b) {
	process temp;

	temp.arrivalTime = a->arrivalTime;
	temp.executionTime = a->executionTime;
	temp.priority = a->priority;
	temp.id = a->id;

	a->arrivalTime = b->arrivalTime;
	a->executionTime = b->executionTime;
	a->priority = b->priority;
	a->id = b->id;

	b->arrivalTime = temp.arrivalTime;
	b->executionTime = temp.executionTime;
	b->priority = temp.priority;
	b->id = temp.id;

}

/*Swap elements alongth the partition for the quick sort algorithm. This is sorting by arrival time*/
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
/*Swap elements along the partition for the quick sort algorithm> This is sorting by priority*/
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
/*pick a pivot for the quick sort algorithm. This is for the priority sorting version of quick sort*/
int quick_sort::priority_pivot(int low, int high, process list[]) {
	int pvt, n;
	n = rand();
	pvt = low + n % (high - low + 1);
	swap(&list[high], &list[pvt]);

	return priority_partition(low, high,list);
}
/*pick a pivot for the quick sort algorithm. This for the arrival time sorting version of quick sort*/
int quick_sort::arrival_pivot(int low, int high, process list[]) {
	int pvt, n;
	n = rand();
	pvt = low + n % (high - low + 1);
	swap(&list[high], &list[pvt]);

	return arrival_partition(low, high,list);
}
/*Sort the list based on arrival time*/
void quick_sort::arrival_sort(int low, int high, process list[]) {
	int pindex;
	if (low < high)
	{
	    pindex = arrival_pivot(low, high,list);
		arrival_sort(low, pindex - 1,list);
		arrival_sort(pindex + 1, high,list);
	}
}
/*Sort the list based on priortiy of the processes*/
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
void priority_calc::new_priority(process & newProcess) {
	if (newProcess.priority < low && newProcess.priority >= veryLow && newProcess.executionTime < low) {
		 newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	else if (newProcess.priority < medium && newProcess.priority >= low && newProcess.executionTime < low) {
		 newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	else if (newProcess.priority < high && newProcess.priority >= medium && newProcess.executionTime < low) {
		 newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	else if (newProcess.priority < veryHigh && newProcess.priority >= high && newProcess.executionTime < low) {
		 newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	else if (newProcess.priority <= max && newProcess.priority >= veryHigh && newProcess.executionTime < low) {
		 newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	else if (newProcess.priority < low && newProcess.priority >= veryLow && newProcess.executionTime < medium && newProcess.executionTime >= low) {
		 newProcess.priority = (rand() % high - medium + 1) + high;
	}
	else if (newProcess.priority < medium && newProcess.priority >= low && newProcess.executionTime < medium && newProcess.executionTime >= low) {
		 newProcess.priority = (rand() % high - medium + 1) + high;
	}
	else if (newProcess.priority < high && newProcess.priority >= medium && newProcess.executionTime < medium && newProcess.executionTime >= low) {
		 newProcess.priority = (rand() % veryHigh - high + 1) + veryHigh;
	}
	else if (newProcess.priority < veryHigh && newProcess.priority >= high && newProcess.executionTime < medium && newProcess.executionTime >= low) {
		 newProcess.priority = (rand() % veryHigh - high+ 1) + veryHigh;
	}
	else if (newProcess.priority <= max && newProcess.priority >= veryHigh && newProcess.executionTime < medium && newProcess.executionTime >= low) {
		 newProcess.priority = (rand() % max - veryHigh + 1) + max;
	}
	else if (newProcess.priority < low && newProcess.priority >= veryLow && newProcess.executionTime < high && newProcess.executionTime >= medium) {
		 newProcess.priority = (rand() % low - veryLow + 1) + low;
	}
	else if (newProcess.priority < medium && newProcess.priority >= low && newProcess.executionTime < high && newProcess.executionTime >= medium) {
		 newProcess.priority = (rand() % medium - low + 1) + medium;
	}
	else if (newProcess.priority < high && newProcess.priority >= medium && newProcess.executionTime < high && newProcess.executionTime >= medium) {
		 newProcess.priority = (rand() % high - medium + 1) + high;
	}
	else if (newProcess.priority < veryHigh && newProcess.priority >= high && newProcess.executionTime < high && newProcess.executionTime >= medium) {
		 newProcess.priority = (rand() % high - medium + 1) + high;
	}
	else if (newProcess.priority <= max && newProcess.priority >= veryHigh && newProcess.executionTime < high && newProcess.executionTime >= medium) {
		 newProcess.priority = (rand() % high - medium + 1) + high;
	}
	else if (newProcess.priority < low && newProcess.priority >= veryLow && newProcess.executionTime < veryHigh && newProcess.executionTime >= high) {
		 newProcess.priority = (rand() % low - veryLow) + low;
	}
	else if (newProcess.priority < medium && newProcess.priority >= low && newProcess.executionTime < veryHigh && newProcess.executionTime >= high) {
		 newProcess.priority = (rand() % low - veryLow) + low;
	}
	else if (newProcess.priority < high && newProcess.priority >= medium && newProcess.executionTime < veryHigh && newProcess.executionTime >= high) {
		 newProcess.priority = (rand() % medium - low) + medium;
	}
	else if (newProcess.priority < veryHigh && newProcess.priority >= high && newProcess.executionTime < veryHigh && newProcess.executionTime >= high) {
		 newProcess.priority = (rand() % medium - low) + medium;
	}
	else if (newProcess.priority <= max && newProcess.priority >= veryHigh && newProcess.executionTime < veryHigh && newProcess.executionTime >= high) {
		 newProcess.priority = (rand() % medium - low) + medium;
	}
	else if (newProcess.priority < low && newProcess.priority >= veryLow && newProcess.executionTime < max && newProcess.executionTime >= veryHigh) {
		 newProcess.priority = (rand() % low - veryLow) + low;
	}
	else if (newProcess.priority < medium && newProcess.priority >= low && newProcess.executionTime < max && newProcess.executionTime >= veryHigh) {
		 newProcess.priority = (rand() % low - veryLow) + low;
	}
	else if (newProcess.priority < high && newProcess.priority >= medium && newProcess.executionTime < max && newProcess.executionTime >= veryHigh) {
		 newProcess.priority = (rand() % low - veryLow) + low;
	}
	else if (newProcess.priority < veryHigh && newProcess.priority >= high && newProcess.executionTime < max && newProcess.executionTime >= veryHigh) {
		 newProcess.priority = (rand() % medium - low) + medium;
	}
	else if (newProcess.priority <= max && newProcess.priority >= veryHigh && newProcess.executionTime < max && newProcess.executionTime >= veryHigh) {
		 newProcess.priority = (rand() % medium - low) + medium;
	}

	else 
	{
		cout << "Error with calculating new priority";
	}
	

}


//Calculating the frequency at which a process has the same arrival time
int priority_calc::same_arrival_freq(int min, process list[]) {
	int i = 0;
			
	while (list[min].arrivalTime == list[min + 1].arrivalTime) {
		min++;
		i++;
		}
			i++;

	return i;

}
/*Execute the processes list using a queue structure. First, sort all the processes based on arrival time and then with priority.
While their is still processes in the processes list, run through them and execute the first process in the queue. When the execution
time of the currently executing process reaches 0, then remove it from the queue and move onto the next process in the list.
When ever an execution time mod(10) = 1 (chosen randomoly, it doesnt matter) prompt the user if they want to add another process.
If another process is added, sort the list again by arrival time and priority.*/
void priority_calc::execute(queue & list) {
	
	int i = 0, count = 0, num = 0;
	string decision;
	highest_priority_calc(list.arr,list.count);

	while (!list.is_empty()) {
		cout << "Executing process id: " << list.arr[list.front].id << endl;
		cout << "Process priority is: " << list.arr[list.front].priority << endl;
		cout << "Process execution time remaining: " << list.arr[list.front].executionTime << endl;
		Sleep(1000);

		list.arr[list.front].executionTime--;
		count++;

		if (list.arr[list.front].executionTime % 10 == 1) {
			cout << "Do you want to add another process?" << endl;
			cin >> decision;
			if (decision == "yes") {
				cout << "How many processes?";
				cin >> num;
				for (int z = 0; z < num; z++) {
					cout << "A new process is being added to the queue: " << endl;
					if (list.front != list.capacity) {
						process *temp = new process;
						temp->id = list.arr[list.rear].id + 1;
						temp->arrivalTime = count;
						cout << "Enter process priority between 0 - 25" << endl;
						cin >> temp->priority;
						cout << "Enter process execution time between 0-25" << endl;
						cin >> temp->executionTime;
						list.enqueue(*temp);
						delete temp;
					}
				}

				highest_priority_calc(list.arr,list.count);
			}
		}
		

		if (list.arr[list.front].executionTime == 0) {
			if (list.rear != list.front)
				list.dequeue();
			else {
				cout << "All process executed";
				exit(1);
			}
		}
	}
	delete list.arr;
}
/*Sort the processes based on their arrival time and their prioritys.*/
void priority_calc::highest_priority_calc(process list[],int count) {
	int x = 0, placeHolder = 0;
	quick_sort obj;

	for (int r = 0; r < count; r++) {
		new_priority(list[r]);
	}

	obj.arrival_sort(0, count-1, list);

	for (int j = 0; j < count; j++) {
		x = same_arrival_freq(x, list);
		if (x > 1) {
			process *temp = new process[x];
			if (j == 0) {
				placeHolder = 0;
				for (int k = 0; k < x; k++) {
					temp[k] = list[placeHolder];
					placeHolder++;
				}
				placeHolder--;
				obj.priority_sort(0, x - 1, temp);
				for (int t = 0; t < x; t++) {
					list[t] = temp[placeHolder];
					placeHolder--;

				}
				delete temp;
			}

			else {
				placeHolder = x;
				for (int k = 0; k < x; k++) {
					temp[k] = list[placeHolder];
					placeHolder++;
				}

				obj.priority_sort(0, x - 1, temp);
				for (int t = 0; t < x; x++) {
					list[t + x] = temp[placeHolder];
					placeHolder--;
				}
				delete temp;
			}
		}

		
	}
	
}
/*Constructor for the queue data structure*/
queue::queue(int size) {
	arr = new process[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;

}
/*delete the queue array*/
queue::~queue() {
	delete arr;
}
/*remove the front process from the queue*/
void queue::dequeue() {
	if (is_empty()) {
		cout << "Queue empty";
		exit(EXIT_FAILURE);
	}

	front = (front + 1) % capacity;
	count--;
}
/*add a process to the back of the queue*/
void queue::enqueue(process p) {
	if (is_full()) {
		cout << "Queue full";
	}

	rear = (rear + 1) % capacity;
	arr[rear] = p;
	count++;
}
/*return queue size*/
int queue::size() {
	return count;
}
/*check if queue is empty*/
bool queue::is_empty() {
	return (size() == 0);
}
/*Check if the queue is full*/
bool queue::is_full() {
	return (size() == capacity);
}
