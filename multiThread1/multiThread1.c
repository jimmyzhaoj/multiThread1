
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>



static int iFlag=1;

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{
	printf("Thread inside %d \n", GetCurrentThreadId());
	while (iFlag)
	{
		printf("The parameter: %u.\n", *(DWORD*)lpParam);
		Sleep(1000);
	}
	return 0;
}



int main(int argc, char* argv[])
{
	HANDLE myhandle;
	DWORD mythreadid, dwThrdParam = 1000;


	myhandle = CreateThread(
		NULL, // default security attributes
		0, // use default stack size
		MyThreadFunction, // thread function
		&dwThrdParam, // argument to thread function
		0, // use default creation flags
		&mythreadid); // returns the thread identifier

	if (myhandle == NULL)
		printf("CreateThread() failed, error: %d.\n", GetLastError());
	else
		printf("It seems the CreateThread() is OK lol!\n");
	printf("Thread here %d \n", GetCurrentThreadId());
	getchar();
	iFlag = 0;
	if (CloseHandle(myhandle) != 0)
		printf("Handle to thread closed successfully.\n");
	printf("Thread outside %d \n", GetCurrentThreadId());
	getchar();
	return 0;
} 