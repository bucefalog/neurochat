#pragma once

struct BandPower {
	double alpha=0;
	double low_beta=0;
	double high_beta=0;
};


int initBCI();
void closeBCI();

int getBandPowers(BandPower powers[]);
int classify(BandPower powers[]);
