#include <iostream>
#include <fstream>

#define MIN_DETECTABLE_FUEL 6

using namespace std;

// Func declarations
int simpleFuelCalc();
int advancedFuelCalc();

// Run both simulations
int main() {
	cout << simpleFuelCalc() << "\n";
	cout << advancedFuelCalc() << "\n";
}

// Simple calculation (fuel mass not taken into account)
int simpleFuelCalc() {
	ifstream file;
	file.open("input");
	int sum = 0;
	int module;
	while (file >> module) {
		sum += ((module / 3) - 2);
	}
	return sum;
}

// Advanced calculation (fuel mass taken into account)
int advancedFuelCalc() {
	ifstream file;
	file.open("input");
	int sum = 0;
	int fuelPerModule;
	while (file >> fuelPerModule) {
		while (fuelPerModule > MIN_DETECTABLE_FUEL)	{
			fuelPerModule = fuelPerModule / 3 - 2;
			sum += fuelPerModule;
		}
	}
	return sum;
}
