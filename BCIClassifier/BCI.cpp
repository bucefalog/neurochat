#include "BCI.h"



#include "IEmoStateDLL.h"
#include "Iedk.h"
#include "IedkErrorCode.h"
#include <iostream>
#include <mutex>
#include <Windows.h>
#include <thread>
#include <atomic>

namespace{

	std::mutex global_mutex;
	std::atomic<unsigned int> userID(0);
	std::atomic<bool>		  processMessages(false);
	std::thread processorThread;

}


void processMessagesThread() {

	EmoEngineEventHandle eEvent = IEE_EmoEngineEventCreate();
	unsigned int auxUserID = 0;

	while(processMessages){

		if (IEE_EngineGetNextEvent(eEvent) == EDK_OK)
		{
			IEE_Event_t eventType = IEE_EmoEngineEventGetType(eEvent);
			IEE_EmoEngineEventGetUserId(eEvent, &auxUserID);

			//std::cout << " type: " << eventType << std::endl;

			switch (eventType) {
			case IEE_UserAdded:
			
				userID = auxUserID;
				
				//std::cout << "User added" << std::endl;
				IEE_FFTSetWindowingType(auxUserID, IEE_HAMMING);
				break;
				//std::cout << header << std::endl;
			default:
				break;
			}

		}

		Sleep(20);

	}

	IEE_EmoEngineEventFree(eEvent);

}


int initBCI() {
	if (IEE_EngineConnect() != EDK_OK) {
		return -1;
	}
	//Engine started, run message processing thread
	processMessages = true;
	processorThread = std::thread(processMessagesThread);
	return 0;

}


void closeBCI() {
	processMessages = false; //signal process to be done
	processorThread.join();    //wait for process to close
	IEE_EngineDisconnect();
}




int getBandPowers(BandPower powers[]) {
	
	IEE_DataChannel_t channelList[2] = { IED_AF3, IED_AF4 };
	double dummy=0;
	unsigned int auxUserID = userID;

	for (int i = 0; i < 2 ; ++i)
		if (IEE_GetAverageBandPowers(auxUserID, channelList[i], &dummy, &powers[i].alpha, &powers[i].low_beta, &powers[i].high_beta, &dummy) != EDK_OK) return -1;
	
	return 0;
	
}

#define RELAXED   0
#define FOCUSED   1
#define WONDERING 2

int lastResult = -1;
double differenceThreshold = 20;

int classify(BandPower powers[]) {
	BandPower combined;
	for (int i = 0; i < 2; i++) {
		combined.alpha	 += powers[i].alpha;
		combined.low_beta  += powers[i].low_beta;
		combined.high_beta += powers[i].high_beta;
	}

	double highest = combined.alpha;
	int result = RELAXED;

	if (combined.low_beta > combined.high_beta) {
		if (combined.low_beta > combined.alpha) {
			highest = combined.low_beta;
			result = WONDERING;
		}
	}
	else if (combined.high_beta > combined.alpha) {
		highest = combined.high_beta;
		result = FOCUSED;
	}
	
	return result;
}


