#include<iostream>
#include<cstdlib>



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

struct process {
	float executionTime=0;
	float priority=0;
	float arrivalTime=0;
};

class priority_calc {
public:
	float new_priority(process);

	int max = 25;
	int veryHigh = 20;
	int high = 15;
	int medium = 10;
	int low = 5;
	int veryLow = 0;
};

float priority_calc::new_priority(process newProcess) {
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

}

using namespace std;
int main() {
	priority_calc obj;
	process test;

	test.priority = obj.new_priority(test);
	cout << test.priority;

}