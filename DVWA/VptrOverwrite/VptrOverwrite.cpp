// VptrOverwrite.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <windows.h>

class IPrinter
{
public:
	virtual void Print(char *str) = 0;
};

class ConsolePrinter : public IPrinter
{
public:
	virtual void Print(char *str) override
	{
		printf("%s", str);
	}
};
#pragma optimize( "", off )
void ProcessInput(char *str, int size)
{
	IPrinter *printer = NULL;
	ConsolePrinter consolePrinter;
	printer = &consolePrinter;
	char inputCopy[MAX_PATH]{};

	memcpy(inputCopy, str, size);
	printer->Print(inputCopy);
}
#pragma optimize( "", on )

int main(int argc, char *argv[])
{
	if (argc < 1) {
		std::cout << "Usage: Pass a file path via commandline" << std::endl;
		return -1;
	}

	char buffer[2048]{};
	HANDLE h = ::CreateFileA(argv[1], FILE_READ_ACCESS, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (h == INVALID_HANDLE_VALUE) {
		return -1;
	}

	DWORD bytesRead = 0;
	if (!::ReadFile(h, buffer, 2048, &bytesRead, NULL)) {
		return -1;
	}

	CloseHandle(h);

	ProcessInput(buffer, bytesRead);

	return 0;
}
