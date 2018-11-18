#include "sharedmemory.h"

#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>


namespace {

	#define BUF_SIZE 4                      //SM size
	TCHAR szName[] = TEXT("bciSharedMem");  //name of SM space

	//HANDLES TO SHARED MEM
	HANDLE hMapFile;
	LPCTSTR pBuf;



}



int initSharedMemory() {

	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // use paging file
		nullptr,                 // default security
		PAGE_READWRITE,          // read/write access
		0,                       // maximum object size (high-order DWORD)
		BUF_SIZE,                // maximum object size (low-order DWORD)
		szName);                 // name of mapping object


	if (hMapFile == nullptr)
	{
		_tprintf(TEXT("Could not create file mapping object (%d).\n"),
			GetLastError());
		system("pause");
		return 1;
	}



	pBuf = static_cast<LPTSTR>(MapViewOfFile(hMapFile,   // handle to map object
		FILE_MAP_ALL_ACCESS, // read/write permission
		0,
		0,
		BUF_SIZE));



	if (pBuf == nullptr)
	{
		_tprintf(TEXT("Could not map view of file (%d).\n"),
			GetLastError());

		CloseHandle(hMapFile);

		return 1;
	}


	smWriteId(-1);

	return 0;
}


void smWriteId(int id) {
	CopyMemory((PVOID)pBuf, &id, sizeof(int));

}
void closeSharedMemory() {
	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);
}
