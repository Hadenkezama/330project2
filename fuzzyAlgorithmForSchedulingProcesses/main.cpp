#include "fuzzy.h"


int main() {
	
	process test1, test2, test3, test4, test5;
	priority_calc obj;

	test1.arrivalTime = 0;
	test2.arrivalTime = 0;
	test3.arrivalTime = 1;
	test4.arrivalTime = 1;
	test5.arrivalTime = 2;

	test1.executionTime = 3;
	test2.executionTime = 13;
	test3.executionTime = 5;
	test4.executionTime = 2;
	test5.executionTime = 6;

	test1.id = 1;
	test2.id = 2;
	test3.id = 3;
	test4.id = 4;
	test5.id = 5;

	test1.priority = 20;
	test2.priority = 15;
	test3.priority = 9;
	test4.priority = 22;
	test5.priority = 13;

	process list[MAX_PROCESS] = { test1,test2,test3,test4,test5 };
	
	obj.highest_priority_calc_execute(list);

}