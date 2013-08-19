#include <iostream>
#include "NvidiaGPU.h"
#include <string>

using namespace std;

int main() {

	NvidiaGPU nGPU;

	// print name and current temperature
	cout << nGPU.getFullName() << endl;
	cout << nGPU.getCurrentTemp() << endl;

	// wait
	cin.get();

	return EXIT_SUCCESS;
}