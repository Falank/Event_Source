//#include <stdio.h>
//extern "C"
//{
//	__declspec(dllexport) void DisplayHelloFromMyDLL()
//	{
//		printf("Hello DLL.\n");
//	}
//}
#include "stdafx.h"
#include "windows.h"

extern "C"
{
	HANDLE hEventLog = NULL;

	__declspec(dllexport) int NativeRegisterEventSource()
	{
		CoInitialize(NULL); // Add this only if running this code in a stand alone application. // if this code is part of an web app, this is not required.

		WCHAR* testStrings[2] = { L"test1 ", L"test2" };

		HANDLE hEventLog = RegisterEventSourceW(NULL, L"TestSource");
		if (hEventLog == NULL)
		{
			printf("Registering event source failed\n");
			return 0;
		}

		if (ReportEventW(hEventLog, EVENTLOG_ERROR_TYPE, 0, 1, NULL, 2, 0, (LPCWSTR*)testStrings, NULL) == 0)
		{
			printf("report event failed : %08x\n", GetLastError());
		}

		DeregisterEventSource(hEventLog);

		CoUninitialize(); // add this only if running this code in a stand alone application. // if this code is part of web app, this is not required.

		return 0;

		//hEventLog = RegisterEventSourceW(NULL, L"TestSource");

		//if (hEventLog == NULL)
		//{
		//	printf("Registering event source failed\n");
		//	return 1;
		//}

		//return 0;
	}


	__declspec(dllexport) int NativeReportEvent()
	{
		CoInitialize(NULL); // Add this only if running this code in a stand alone application. // if this code is part of an web app, this is not required.

		WCHAR* testStrings[2] = { L"test1 ", L"test2" };

		HANDLE hEventLog = RegisterEventSourceW(NULL, L"TestSource");
		if (hEventLog == NULL)
		{
			printf("Registering event source failed\n");
			return 0;
		}

		if (ReportEventW(hEventLog, EVENTLOG_ERROR_TYPE, 0, 1, NULL, 2, 0, (LPCWSTR*)testStrings, NULL) == 0)
		{
			printf("report event failed : %08x\n", GetLastError());
		}

		DeregisterEventSource(hEventLog);

		CoUninitialize(); // add this only if running this code in a stand alone application. // if this code is part of web app, this is not required.

		return 0;

		//WCHAR* testStrings[2] = { L"test1 ", L"test2" };

		//if (ReportEventW(hEventLog, EVENTLOG_ERROR_TYPE, 0, 1, NULL, 1, 0, (LPCWSTR*)testStrings, NULL) == 0)
		//{
		//	printf("report event failed : %08x\n", GetLastError());
		//	return 1;
		//}
		//return 0;
	}

}