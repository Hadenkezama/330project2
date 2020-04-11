#include "fuzzy.h"


int main() {
	
	process test1, test2, test3, test4, test5;
	priority_calc obj;
	queue obj1;

	test1.arrivalTime = 0;
	test2.arrivalTime = 0;
	test3.arrivalTime = 1;
	
	test1.executionTime = 3;
	test2.executionTime = 4;
	test3.executionTime = 5;
	
	test1.id = 1;
	test2.id = 2;
	test3.id = 3;
	
	test1.priority = 20;
	test2.priority = 15;
	test3.priority = 9;
	

	
	obj1.enqueue(test1);
	cout << obj1.rear <<endl;
	cout << obj1.front << endl;
	obj1.enqueue(test2);
	cout << obj1.rear <<endl;
	cout << obj1.front << endl;
	obj1.enqueue(test3);
	cout << obj1.rear <<endl;
	cout << obj1.front << endl;
	
	
	obj.execute(obj1);
	

	
	
	return 1;
}