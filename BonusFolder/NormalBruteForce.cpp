#include "stdafx.h";
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double BDelay, ADelay;

	cout << "Hydrophone B Delay: ";
	cin >> BDelay;
	//BDelay = 0.000263474;

	cout << "Hydrophone A Delay: ";
	cin >> ADelay;
	//ADelay = 0.000707023;


	double diff = BDelay * 1481; //Distance difference from sound origin: Point B & Point C
	double diff2 = ADelay * 1481; //Distance difference from sound origin: Point A & Point C
	bool stop = false;
	for (double x = -5; x<5; x = x + 0.002) {
		if (stop == true) {
			break;
		}
		for (double y = -5; y<5; y = y + 0.002) {
			//S = sound
			double distSC = sqrt(pow(x, 2) + pow((y - 1), 2));
			double distSB = sqrt(pow((x + 0.5), 2) + pow((y), 2));
			double distSA = sqrt(pow((x - 0.5), 2) + pow((y), 2));

			if ((abs(distSB - distSC - diff) < 0.0001) && (fabs(distSA - distSC - diff2) < 0.0001)) {
				cout << x << endl;
				cout << y << endl;
				stop = true;
				break;
			}
		}
	}
	system("PAUSE");
}