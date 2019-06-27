// IntegerOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <windows.h>

#define MAX_HEADER 80

#pragma optimize( "", off )
void ProcessInput(char *str, int size, int headersize)
{
	if ((size + (headersize * 2)) >= MAX_PATH) {
		return;
	}

	char inputCopy[MAX_PATH]{};
	int offset = 0;

	// insert header
	if (headersize > 0 && headersize < MAX_HEADER) {
		for (int i = 0; i < headersize - 1; ++i) {
			inputCopy[offset++] = '*';
		}
		inputCopy[offset++] = '\n';
	}

	// insert actual contents
	memcpy(inputCopy + offset, str, size);

	// insert footer
	if (headersize > 0 && headersize < MAX_HEADER) {
		offset += size;
		inputCopy[offset++] = '\n';
		for (int i = 0; i < headersize - 1; ++i) {
			inputCopy[offset++] = '*';
		}
	}

	printf(inputCopy);
}
#pragma optimize( "", on )

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << "Usage: Pass a file path and header size via commandline" << std::endl;
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

	int headersize = atoi(argv[2]);

	ProcessInput(buffer, bytesRead, headersize);

	return 0;
}
