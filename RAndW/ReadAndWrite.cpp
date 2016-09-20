#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;


int main(){
	ifstream infile ("In.txt");
	ofstream outfile ("Out.txt");

	int a,b,c;
	vector <int> tab;
	tab.resize(0);

	while (infile >> a >> b >> c){
		int dist = round(sqrt(pow(a,2)+pow(b,2)+pow(c,2)));
		cout << dist << endl;
		outfile << dist << endl;
		if (dist > 200){
			tab.resize(tab.size(););
			tab.push_back(dist);
		}
	}
	oufile << "Distances over 200:" < endl;

	for (int i = 0;i<tab.size();i++){
		outfile << tab[i] << endl;
	}
}