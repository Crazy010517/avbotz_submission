#include "stdafx.h";
#include <iostream>
#include <cmath>
using namespace std;


double BDelay, ADelay;
double diff = BDelay * 1481; //Distance difference from sound origin: Point B & Point C
double diff2 = ADelay * 1481; //Distance difference from sound origin: Point A & Point C
double XBound = -200, XBound2 = 200, YBound = -200, YBound2 = 200;

bool CheckRange(double incre) {
	bool stop = false;
	cout << "Looking with increments of ";
	cout << incre << endl;
	for (double x = XBound; x<XBound2; x = x + incre) {
		if (stop == true) {
			break;
		}

		for (double y = YBound; y < YBound2; y = y + incre) {
			//S = sound
			double distSC = sqrt(pow(x, 2) + pow((y - 1), 2));
			double distSB = sqrt(pow((x + 0.5), 2) + pow((y), 2));
			double distSA = sqrt(pow((x - 0.5), 2) + pow((y), 2));
			
			
			bool e1 = (abs(distSB - distSC - diff) <= (incre / 10));
			bool e2 = (abs(distSA - distSC - diff2) <= (incre / 10));
			if ((e1 == true) && (e2 == true)) {
				cout << "Found" << endl;
				double safetymargin = incre*100;
				XBound = x - incre - safetymargin;
				XBound2 = x + incre + safetymargin;
				YBound = y - incre - safetymargin;
				YBound2 = y + incre + safetymargin;
				cout << x << endl;
				cout << y << endl;
				stop = true;
				break;
			}
		}
	}
	if (stop == true) {
		return true;
	}
	else {
		cout << "None found" << endl;
		return false;
	}
}

int main() {
	double default;
	cout << "Would you like to run this program with the default locations of the hydrophones and sound? 1 = Yes or 2 = No?";
	cin >> default;

	if (default == 1) {
		BDelay = 0.000263474;
		ADelay = 0.000707023;
		diff = BDelay * 1481;
		diff2 = ADelay * 1481;
	}else{
		cout << "Hydrophone B Delay: ";
		cin >> BDelay;

		cout << "Hydrophone A Delay: ";
		cin >> ADelay;
	}
	double Increment =  0.1;
	bool Found = true;
	for (int i = 0; i < 7; i++) {
		if (Found == true) {
			CheckRange(Increment);
			Increment = Increment * pow(10, -1);
		}
		else {
			break;
		}
	}
	getchar();
	system("PAUSE");
}