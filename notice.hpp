/****************************************************************

	notice.hpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#ifndef CBOX_NOTICE_HPP
#define CBOX_NOTICE_HPP

#include <string>
#include <iostream>
#include <tchar.h>
#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)

// Windows

#include <windows.h>

namespace cbox
{

	void addTrayIcon(HWND hWnd)
	{
		NOTIFYICONDATA nid{};
		nid.cbSize = sizeof(nid);
		nid.uID = 1000u;
		nid.hWnd = hWnd;
		nid.uFlags = NIF_ICON | NIF_TIP;
		nid.hIcon = LoadIcon(NULL, IDI_INFORMATION);
		lstrcpy(nid.szTip, _TEXT("NotifyMessage"));
		::Shell_NotifyIcon(NIM_ADD, &nid);
	}

	template <typename T>
	void notice(T title, T message)
	{
		HWND hwnd = ::GetConsoleWindow();
		addTrayIcon(hwnd);
		if (hwnd)
		{
			NOTIFYICONDATA nid{};
			nid.cbSize = sizeof(nid);
			nid.hWnd = hwnd;
			nid.uID = 1000u;
			nid.uFlags = NIF_INFO;
			nid.dwInfoFlags = NIIF_INFO;

			lstrcpy(nid.szInfoTitle, title);
			lstrcpy(nid.szInfo, message);

			::Shell_NotifyIcon(NIM_MODIFY, &nid);
		}
	}
}

#else

// UNIX

namespace cbox
{
	template <typename T>
	void notice(T title, T message)
	{
		// NOTE: Show notifications for Windows only
	}
}

#endif

#endif // CBOX_NOTICE_HPP
