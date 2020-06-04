/*
Shakra Driver component
This .cpp file contains the required code to run the driver.

This file is required for both Windows and Linux.
*/

#pragma once

#ifndef BASS_HPP
#define BASS_HPP

#ifdef _WIN32

#define BASSDEF(f) (WINAPI *f)
#define F _T(__FUNCTION__)

#include <Windows.h>
#include <ShlObj_core.h>
#include <tchar.h>
#include "inc/win32/bass.h"
#include "WinError.hpp"

#elif __linux__

// stub

#elif __APPLE__

// stub

#endif

class BASS {
private:
	wchar_t* CustomDir;
	int OutputID;
	int AudioFreq;
	int Flgs;
	bool _Fail = false;

#ifdef _WIN32
	HMODULE BASSLib = nullptr;
#elif __linux__
	// stub
#elif __APPLE__
	// stub
#endif

	ErrorSystem BASSErr;

	bool LoadLib();
	bool FreeLib();

public:
	// Only used by apps that are bundled with the driver
	bool SetCustomLoadDir(wchar_t*, size_t);

	bool Fail() const { return _Fail; }

	// Init
	BASS(int, int);
	BASS(int, int, int);
};

#endif