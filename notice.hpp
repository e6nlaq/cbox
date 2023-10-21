/****************************************************************

	notice.hpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

// Program Reference (Best Answer)
// https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11199407356

#ifndef CBOX_NOTICE_HPP
#define CBOX_NOTICE_HPP

#include <string>
#include <iostream>
#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)

// Windows

#include <windows.h>
#include <tchar.h>

namespace cbox
{

	void __addTrayIcon(HWND hWnd)
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
		__addTrayIcon(hwnd);
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

template <typename T>
inline constexpr T _T(T x) noexcept
{
	return x;
}

namespace cbox
{

	template <typename T>
	inline void notice(T title, T message) noexcept
	{
		// Show notifications for Windows only
	}
}

#endif

#endif // CBOX_NOTICE_HPP
