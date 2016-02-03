/*
	Project Euler question Number 1
	Multiples of 3 and 5
	January 27, 2016
*/
	#include <iostream>
	using namespace std;

int main(){
	unsigned int total = 0;

	for(int i = 3; i < 1000; i++){
		if(i % 3 == 0 || i % 5 == 0){
			total += i;
		}
	}

	cout << total << endl;

	return 0;
}