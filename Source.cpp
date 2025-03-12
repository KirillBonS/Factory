#include "class.h"
#include <iostream>
#include <string>
#include  <fstream>

using namespace std;

int main() {
	plan for_1[4] = { plan(4,3), plan(4,4), plan(5,4), plan(5,3) };
	plan for_2[4] = { plan(3,3), plan(4,4), plan(4,4), plan(3,3) };
	plan for_3[4] = { plan(12,10), plan(8,6), plan(10,7), plan(8, 7) };
	plan for_4[4] = { plan(15,12), plan(15,13), plan(10,11), plan(12,11) };
	plan for_5[4] = { plan(12, 9), plan(10, 10), plan(11, 7), plan(10, 8) };


	Factory** arr = new Factory*[6];
	arr[0] = new Factory("Wonka", "Sweets", for_1);
	arr[1] = new Factory("Fanta", "Fantasy", for_2);
	arr[2] = new Factory("Castle", "Knights", for_3);
	arr[3] = new Factory("SFEDU", "Students", for_4);
	arr[4] = new Factory("Beeline", "Honey", for_5);
	arr[5] = new Factory;

	//задание1
	const int N = 6;

	Factory* loc = nullptr;

	for (int p = 0; p < N - 1; p++) {
		for (int j = 0; j < N - p - 1; j++) {
			if (arr[j]->get_QS() > arr[j + 1]->get_QS()) {
				loc = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = loc;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << *arr[i];
	}

	//задание2
	int cnt = 0;
	bool flag = true;
	for (int i = 0; i < N; i++) {
		plan* temp1 = arr[i]->get_Q();
		for (int k = 0; k < 4; k++) {
			if (temp1[k].get_A() != temp1[k].get_E() and flag)
				flag = false;
		}
		if (!flag) { ++cnt; }
		flag = true;
	}

	cout << cnt;

	return 0;
}

//append arr[i]

/*const int N = 6;
	for (int i = 0; i < N; i++) {
		plan* K = arr[i].get_Q();
		for (int k = 0; k < N; k++) {

		}
	}*/

//for (int k = 0; k < 4; k++) {
//	if (arr[k]->get_A() != arr[k]->get_E()) // temp[k] = plan
//		arr[i - cnt] = arr[i];
//	else cnt++;
//}