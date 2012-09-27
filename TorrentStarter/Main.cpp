#include <windows.h>
#include <string>
#include "GetProcessID.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 
  DWORD previous = 0; 
  int numberOfMins = 30*60;
  //numberOfMins = numberOfMins*60;
  std::string applicationName = "uTorrent";
  std::string startApplicationWithName = "start " + applicationName;
  while(true)
  {
    LASTINPUTINFO info; 
    info.cbSize = sizeof(info);
    GetLastInputInfo(&info);
    DWORD idleSeconds = (GetTickCount() - info.dwTime)/1000;

    if (idleSeconds < previous) 
    {

      //printf("Idle time: %i\n",previous);
    }
	if(idleSeconds == numberOfMins)
	{
	 	std::vector<DWORD> SetOfPID;
		GetProcessID(applicationName.c_str(),SetOfPID);
		if (SetOfPID.empty())		// Process is not running
		{
			system(startApplicationWithName.c_str());
			//system("start uTorrent.exe");
		}
	}

	//if (AppIsAllreadyRunning() == false)
	//	started = false;

    Sleep(1000);
    previous = idleSeconds; 

  }


    




	
	return 0;
}

