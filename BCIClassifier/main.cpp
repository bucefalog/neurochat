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



int  main()
{
	if (initSharedMemory() != 0) return -1;
	if (initBCI() != 0) {
		closeSharedMemory();
		return -1;
	}

		
	std::cout << "===================================================================\n";
	std::cout << "  Example to get the average band power for a specific channel from \n the latest epoch\n";
	std::cout << "===================================================================\n";
	
	//double max = std::numeric_limits<double>::max();
	while (!_kbhit()) {

		BandPower powers[2] = {BandPower(),BandPower()};
		if (getBandPowers(powers) == 0) {
			std::cout << "(" << powers[0].alpha << "," << powers[1].alpha << ")  "
				<< "(" << powers[0].low_beta << "," << powers[1].low_beta << ")  "
				<< "(" << powers[0].high_beta << "," << powers[1].high_beta << ")\n";

			//std::cout << "(" << powers[0].alpha << "," << powers[1].alpha << ")  "
			//	<< "(" << powers[0].low_beta << "," << powers[1].low_beta << ")  "
			//	<< "(" << powers[0].high_beta << "," << powers[1].high_beta << ")\n";

			smWriteId(classify(powers));
		}

		Sleep(50);

	}

	system("pause");

	closeBCI();
	closeSharedMemory();
	return 0;
}


