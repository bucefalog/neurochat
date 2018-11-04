#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define MAX_THREADS 3
#define BUF_SIZE 255

DWORD WINAPI MyThreadFunction( LPVOID lpParam );
void ErrorHandler(LPTSTR lpszFunction);

// Sample custom data structure for threads to use.
// This is passed by void pointer so it can be any data type
// that can be passed using a single void pointer (LPVOID).
typedef struct MyData {
    int val1;
    int val2;
} MYDATA, *PMYDATA;


// MUTEX:
HANDLE mutex;



int _tmain()
{
	//CREATE MUTEX:
	mutex = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);             // unnamed mutex

	if (mutex == NULL)
	{
		printf("CreateMutex error: %d\n", GetLastError());
		return 1;
	}



    PMYDATA pDataArray[MAX_THREADS];
    DWORD   dwThreadIdArray[MAX_THREADS];
    HANDLE  hThreadArray[MAX_THREADS]; 

    // Create MAX_THREADS worker threads.

    for( int i=0; i<MAX_THREADS; i++ )
    {
        // Allocate memory for thread data.

        pDataArray[i] = (PMYDATA) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                sizeof(MYDATA));

        if( pDataArray[i] == NULL )
        {
           // If the array allocation fails, the system is out of memory
           // so there is no point in trying to print an error message.
           // Just terminate execution.
            ExitProcess(2);
        }

        // Generate unique data for each thread to work with.

        pDataArray[i]->val1 = i;
        pDataArray[i]->val2 = i+100;

        // Create the thread to begin execution on its own.

        hThreadArray[i] = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            MyThreadFunction,       // thread function name
            pDataArray[i],          // argument to thread function 
            0,                      // use default creation flags 
            &dwThreadIdArray[i]);   // returns the thread identifier 


        // Check the return value for success.
        // If CreateThread fails, terminate execution. 
        // This will automatically clean up threads and memory. 

        if (hThreadArray[i] == NULL) 
        {
			ErrorHandler((LPTSTR)"text");//TEXT("CreateThread"));
           ExitProcess(3);
        }
    } // End of main thread creation loop.

    // Wait until all threads have terminated.

    WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);

    // Close all thread handles and free memory allocations.

    for(int i=0; i<MAX_THREADS; i++)
    {
        CloseHandle(hThreadArray[i]);
        if(pDataArray[i] != NULL)
        {
            HeapFree(GetProcessHeap(), 0, pDataArray[i]);
            pDataArray[i] = NULL;    // Ensure address is not reused.
        }
    }

	//CLOSE MUEX:
	CloseHandle(mutex);

    return 0;
}


bool cameraClosed = false;



void setCameraClosed(bool value) {

	cameraClosed = cameraClosed;

}

bool getCameraClosed() {

	bool copy = cameraClosed;

	return copy;

}


struct FaceData {
	int x, y;

};

FaceData faceData;

void setFaceData(FaceData &newDetection) {
	DWORD dwWaitResult = WaitForSingleObject(
							mutex,    // handle to mutex
							INFINITE);  // no time-out interval
	switch (dwWaitResult) {
	case WAIT_OBJECT_0:

		faceData = newDetection;
		break;
	case WAIT_ABANDONED:
		break;


	};
}

void getFaceData(FaceData &result) {
	result = faceData;
}

int originalFrame=0;

void newFrameCapture() {
	originalFrame = 0;
}

bool getFrame(int &image) {
	//function returns where the frame is valid

	return false;
}





DWORD WINAPI MyThreadFunction( LPVOID lpParam ) 
{ 
	while (!getCameraClosed()) {

		int frame;
		getFrame(frame);

		//do face detection and fill structure FaceData
		FaceData detection;

		setFaceData(detection);
		


	}



 //   HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
 //   if( hStdout == INVALID_HANDLE_VALUE )
 //       return 1;
 //   
	//
	//PMYDATA pDataArray = (PMYDATA)lpParam;

 //   TCHAR msgBuf[BUF_SIZE];
 //   size_t cchStringSize;
 //   DWORD dwChars;

 //   StringCchPrintf(msgBuf, BUF_SIZE, TEXT("Parameters = %d, %d\n"),pDataArray->val1, pDataArray->val2); 
 //   StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
 //   WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);

    return 0; 
} 



void ErrorHandler(LPTSTR lpszFunction) 
{ 
    // Retrieve the system error message for the last-error code.

    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError(); 

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );

    // Display the error message.

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
        (lstrlen((LPCTSTR) lpMsgBuf) + lstrlen((LPCTSTR) lpszFunction) + 40) * sizeof(TCHAR)); 
    StringCchPrintf((LPTSTR)lpDisplayBuf, 
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"), 
        lpszFunction, dw, lpMsgBuf); 
    MessageBox(NULL, (LPCTSTR) lpDisplayBuf, TEXT("Error"), MB_OK); 

    // Free error-handling buffer allocations.

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}