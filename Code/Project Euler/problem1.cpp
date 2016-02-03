/*
	Project Euler question Number 1
	Multiples of 3 and 5
	January 27, 2016
*/

#include <iostream>
using namespace std;

/*
	Calculates the sum of all integers between 1 and the target inclusive that are
	divisible by the divisor. Runs in O(1).
*/
int sumDivisibleBy(int divisor, int target){
	// Rather then iterating over all integers in the range, checking each of them
	// to see if they are divisible by the divisor, and summing them, we can calculate
	// how many integers are divisible, find the sum of 1 to that, and then multiply by
	// the divisor.
	int p = target / divisor;
	return divisor * (p * (p + 1) ) / 2;
}

int main(){
	int target = 999;

	cout << sumDivisibleBy(3, target) + sumDivisibleBy(5, target) - sumDivisibleBy(15, target) << endl;

	return 0;
}