// Problem a: popular vote

#include <iostream>
using namespace std;

void solve(){
	int n, max, current, winner, total;
	bool single_winner = true;
	total = 0;
	max = 0;
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> current;

		total += current;
		if(current > max){
			single_winner = true;
			max = current;
			winner = i;
		}else if(current == max){
			single_winner = false;
		}
	}

	if(single_winner){
		if(max > total / 2){
			cout << "majority winner " << winner << endl;
		}else{
			cout << "minority winner " << winner << endl;
		}
	}else{
		cout << "no winner\n";
	}

}

int main(){
	int t;

	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}