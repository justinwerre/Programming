#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define MAXSIZE 1000

int findStation(vector<string> &stations, string &s){
	int loc = -1;
	for(int i = 0; i < stations.size(); i++){
		if(stations.at(i) == s){
			loc = i;
			break;
		}
	}

	return loc;
}

int main(){
	int s;
	int graf[MAXSIZE][MAXSIZE];
	vector<string> stations;
	string station;

	cin >> s;
	getline(cin, station);

	for(int i = 0; i < MAXSIZE; i++){
		for(int j = 0; j < MAXSIZE; j++){
			graf[i][j] = 0;
		}
	}

	while(s--){
		getline(cin, station);
		int space = station.find(" ");
		string s = station.substr(0, space);

		int loc = findStation(stations, s);
		if(-1 == loc){
			stations.push_back(s);
			loc = stations.size() - 1;
		}

		int nextspace;
		do{
			nextspace = station.find(" ", space + 1);
			s = station.substr(space + 1, nextspace - space - 1);

			int dloc = findStation(stations, s);
			if(-1 == dloc){
				stations.push_back(s);
				dloc = stations.size() - 1;
			}

			graf[loc][dloc] = 1;
			graf[dloc][loc] = 1;
			space = nextspace;
		}while(nextspace != string::npos);
	}

	getline(cin, station);
	int space = station.find(" ");
	int ss, es;
	vector<int> previous(MAXSIZE, -1);
	queue<int> q;

	string start = station.substr(0, space);
	string end = station.substr(space + 1);
	ss = findStation(stations, start);
	es = findStation(stations, end);
	q.push(ss);

	while(!q.empty() && -1 == previous.at(es)){
		int current = q.front();
		q.pop();

		for(int i = 0; i < stations.size(); i++){
			if(1 == graf[i][current] && -1 == previous.at(i)){
				previous.at(i) = current;
				q.push(i);
			}
		}
	}

	if(-1 == previous.at(es)){
		cout << "no route found\n";

	} else {
		vector<string> route;
		int lastStation = es;
		while(ss != lastStation){
			route.push_back(stations.at(lastStation));
			lastStation = previous.at(lastStation);
		}

		route.push_back(stations.at(ss));

		for(int i = route.size() - 1; i >= 0; i--){
			cout << route.at(i) << " ";
		}
		cout << endl;
	}

	return 0;
}
