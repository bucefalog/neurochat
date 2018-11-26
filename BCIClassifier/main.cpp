/****************************************************************************
**
** Copyright 2015 by Emotiv. All rights reserved
** Example - AverageBandPowers
** The average band power for a specific channel from the latest epoch with
** 0.5 seconds step size and 2 seconds window size
** This example is used for single connection.
**
****************************************************************************/


#include <conio.h>
#include <windows.h>

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cstddef>


#include "sharedmemory.h"
#include "BCI.h"

using namespace std;



void startClassification();
void record(std::string fileName);
void printMessage();
void rawValues();


int  main()
{
	if (initSharedMemory() != 0) return -1;
	if (initBCI() != 0) {
		closeSharedMemory();
		return -1;
	}

		
	
	//double max = std::numeric_limits<double>::max();
	bool done = false;

	printMessage();

	while (!done){
		if (!_kbhit()) {
			Sleep(30);
			continue;
		}

		int key = _getch();

		cout << (char)key << endl << endl;

		switch (key) {
			case 'q':
				done = true;
				break;
			case 'r':
				cout << "Relax with your eyes open\n"
					<< "until you hear the second beeping sound\n";
				system("pause");
				record("relaxed");
				printMessage();
				break;
			case 'f':
				cout << "focus on something\n"
					<< "until you hear the second beeping sound\n";
				system("pause");
				record("focused");
				printMessage();
				break;
			case 's':
				cout << "starting classification...\n";
				Sleep(1000);
				cout << "press any key to stop...\n";
				startClassification();
				printMessage();
				break;
			case 'w':
				cout << "printing raw values, print any key to stop...\n";
				Sleep(1000);
				rawValues();
				printMessage();
				break;
			default:
				cout << "invalid key...\n";
				printMessage();

		}

		

		Sleep(50);
		

	}

	system("pause");

	closeBCI();
	closeSharedMemory();
	return 0;
}


#define RECORD_TIME 12 //record time in seconds
#define DELAY_TIME 125
void record(std::string fileName) {

	ofstream file;
	file.open(fileName + ".txt");

	cout << "recordig in...\n";
	cout << "3\n";
	Sleep(1000);
	cout << "2\n";
	Sleep(1000);
	cout << "1\n";
	Sleep(1000);

	int recordNumber = (RECORD_TIME * 1000) / DELAY_TIME;

	cout << '\a';

	for (int i = 0; i < recordNumber; i++) {

		BandPower powers[2] = { BandPower(),BandPower() };
		if (getBandPowers(powers) == 0) {
			cout << "(" << powers[0].alpha << "," << powers[1].alpha << ")  "
				<< "(" << powers[0].low_beta << "," << powers[1].low_beta << ")  "
				<< "(" << powers[0].high_beta << "," << powers[1].high_beta << ")\n";

			file << powers[0].alpha		<< "," 
				 << powers[0].low_beta	<< "," 
				 << powers[0].high_beta << "," 
				 << powers[1].alpha		<< ","
				 << powers[1].low_beta	<< ","
				 << powers[1].high_beta << "\n";
			
		}
		Sleep(DELAY_TIME);
	}

	cout << '\a';
	file.close();

}
void printMessage() {
	while (_kbhit()) _getch();
	//system("cls");
	cout << endl << endl;
	cout <<"Choose an option: \n"
		<< endl
		<< "r - record relaxed state\n"
		<< "f - record focused state\n"
		<< "s - start classificationg\n"
		<< "w - print raw values\n"
		<< "q - quit\n"
		<< endl
		<< "Selection: ";
}

void startClassification() {

	Sleep(1000);
	while (!_kbhit()) {
		BandPower powers[2] = { BandPower(),BandPower() };
		if (getBandPowers(powers) == 0) {
			cout << "(" << powers[0].alpha << "," << powers[1].alpha << ")  "
				<< "(" << powers[0].low_beta << "," << powers[1].low_beta << ")  "
				<< "(" << powers[0].high_beta << "," << powers[1].high_beta << ")\n";

			smWriteId(classify(powers));
		}
		Sleep(DELAY_TIME);
	}
		
}

void rawValues() {

	Sleep(500);
	while (!_kbhit()) {
		BandPower powers[2] = { BandPower(),BandPower() };
		if (getBandPowers(powers) == 0) {
			cout << "(" << powers[0].alpha << "," << powers[1].alpha << ")  "
				<< "(" << powers[0].low_beta << "," << powers[1].low_beta << ")  "
				<< "(" << powers[0].high_beta << "," << powers[1].high_beta << ")\n";

		}
		Sleep(DELAY_TIME);
	}

}