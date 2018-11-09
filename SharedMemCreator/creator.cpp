#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

#define BUF_SIZE 4
TCHAR szName[] = TEXT("bciSharedMem");

#define num_filters 3

int _tmain()
{
	HANDLE hMapFile;
	LPCTSTR pBuf;

	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		PAGE_READWRITE,          // read/write access
		0,                       // maximum object size (high-order DWORD)
		BUF_SIZE,                // maximum object size (low-order DWORD)
		szName);                 // name of mapping object

	if (hMapFile == NULL)
	{
		_tprintf(TEXT("Could not create file mapping object (%d).\n"),
			GetLastError());
		system("pause");
		return 1;
	}



	pBuf = (LPTSTR)MapViewOfFile(hMapFile,   // handle to map object
		FILE_MAP_ALL_ACCESS, // read/write permission
		0,
		0,
		BUF_SIZE);

	if (pBuf == NULL)
	{
		_tprintf(TEXT("Could not map view of file (%d).\n"),
			GetLastError());

		CloseHandle(hMapFile);

		return 1;
	}





	int value = 0;
	CopyMemory((PVOID)pBuf, &value, sizeof(int));
	bool waiting = true;
	while (waiting) {
	   char input = _getch();
	   printf("read: %c\n", input);

	   switch (input) {
	   case 27: { //pressed escape
		   waiting = false;
		   break;
	   }
	   case 'w': {
		   value = (value+1)%num_filters;
		   printf("setting: %d\n", value);
		   CopyMemory((PVOID)pBuf, &value, sizeof(int));
		   break;
	   }
	   case 's': {
		   value = (value + num_filters- 1) % num_filters;
		   printf("setting: %d\n", value);
		   CopyMemory((PVOID)pBuf, &value, sizeof(int));
		   break;
	   }
	   default: {
		   break;
	   }
	   }



	}

	

	return 0;
}