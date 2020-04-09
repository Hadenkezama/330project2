#include "fuzzy.h"

int main() {
	priority_calc obj;
	process test1, test2, test3, test4, test5;
	arrival_time thing;


	test1.arrivalTime = 2;
	test2.arrivalTime = 4;
	test3.arrivalTime = 2;
	test4.arrivalTime = 1;
	test5.arrivalTime = 5;

	processList[0] = test1;
	processList[1] = test2;
	processList[2] = test3;
	processList[3] = test4;
	processList[4] = test5;

	obj.




	for (int i = 0; i < 5; i++) {
		cout << processList[i].arrivalTime;
	}


}