// GetProcessIDTest.cpp : Defines the entry point for the console application.
//


#include <windows.h>
#include "GetProcessID.h"

int main(int argc, char* argv[])
{
	std::vector<DWORD> SetOfPID;
	GetProcessID("Rundll32",SetOfPID);
	if (SetOfPID.empty())		// Process is not running
	{
		MessageBox(NULL, "Process 'Rundll32' is not running", "Information", MB_OK);
	}
	else					// Process is running
	{
		for (int i=0;i < SetOfPID.size(); i++)
		{
			char szText[256];
			sprintf(szText,"Process ID of 'Rundll32' is %d\n", SetOfPID[i]);
			MessageBox(NULL, szText, "Information", MB_OK);
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,SetOfPID[i]);
			// some code...
			CloseHandle(hProcess);
		}
	}
	return 0;
}
