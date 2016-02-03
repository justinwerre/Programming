/*
	Project Euler question Number 2
	Even Fibonacci Numbers
	Febuary 2, 2016
*/
#include <iostream>
using namespace std;

int main(){
	int a = 1;
	int b = 1;
	int temp;
	int total = 0;
	const int four_million = 4000000;

	while(b < four_million){
		if(b % 2 == 0){
			cout << b << endl;
			total += b;
		}

		temp = b;
		b = b + a;
		a = temp;
	}

	cout << "total: " << total << endl;

	return 0;
}