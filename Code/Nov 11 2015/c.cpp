#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>
using namespace std;

#define EPS 1e-10

bool can(vector<double> & coords, double dist, int c){
	double point = coords.at(0) + dist;
	int points = 1;
	for(size_t i = 0; i < coords.size(); i++){
		if(fabs(point - coords.at(i)) > dist){
			points++;
			point = coords.at(i) + dist;
		}
	}

	return points <= c;
}

vector<double> bsearch(vector<double> &coords, int c){
	sort(coords.begin(), coords.end());
	double lo, hi, mid;
	lo = 0;
	hi = coords.at(coords.size() - 1);

	while(fabs(hi - lo) > EPS){
		mid = (hi + lo) / 2.0;
		if(can(coords, mid, c)){
			hi = mid;
		} else {
			lo = mid;
		}
	}

	vector<double> points;
	double coord = coords.at(0) + mid;
	points.push_back(coord);
	for(size_t i = 0; i < coords.size(); i++){
		if(fabs(coord - coords.at(i)) > mid){
			coord = coords.at(i) + mid;
			points.push_back(coord);
		}
	}

	return points;
}

void solve(){
	int n, c;
	vector<pair<double, double> > bots;
	vector<double> xcoords;
	vector<double> ycoords;
	double x, y;
	cin >> n >> c;

	for(int i = 0; i < n; i++){
		cin >> x >> y;
		bots.push_back(make_pair(x, y));
		xcoords.push_back(x);
		ycoords.push_back(y);
	}

	vector<double> xsites = bsearch(xcoords, c);
	vector<double> ysites = bsearch(ycoords, c);
	vector<pair<double, size_t> > distances;

	for(size_t i = 0; i < xsites.size(); i++){
		for(size_t j = 0; j < ysites.size(); j++){
			for(size_t k = 0; k < bots.size(); k++){
				double x2 = (xsites.at(i) - bots.at(k).first) * (xsites.at(i) - bots.at(k).first);
				double y2 = (ysites.at(j) - bots.at(k).second) * (ysites.at(j) - bots.at(k).second);
				double distance = sqrt(x2 + y2);
				cout << fixed << setprecision(5) << distance << endl;
				distances.push_back(make_pair(distance, i * ysites.size() + j));
			}
		}
	}

	sort(distances.begin(), distances.end());
	vector<int> connections(xsites.size() * ysites.size(), bots.size());
	int sites = xsites.size() * ysites.size();
	size_t biggest = distances.size() - 1;

	while(true){
		if(connections.at(distances.at(biggest).second) > 1){
			connections.at(distances.at(biggest).second)--;
			biggest--;
		}else if(sites > c){
			connections.at(distances.at(biggest).second)--;
			biggest--;
			sites--;
		}else {
			cout << "answer: " << fixed << setprecision(5) << distances.at(biggest).first << endl;
			break;
		}
	}
}

int main(){
	int c;
	cin >> c;
	while(c--){
		solve();
	}

	return 0;
}