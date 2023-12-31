/****************************************************************

	main.cpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#ifndef __cplusplus
#error Must be compiled in C++.
#endif

#include <vector>
#include <string>
#include <iostream>
#include "args.hpp"
#include "version.hpp"
#include "system.hpp"
#include "console.hpp"
#include "init.hpp"

// #define CBOX_DEBUG

#ifdef CBOX_DEBUG
#include <algocpp/all.hpp>
#endif

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

int main(int argc, char const *argv[])
{

// Enable escape sequence
#if defined(_WIN32) || defined(_WIN64)
	// In Windows, assert works, so a blank space is not acceptable.
	std::system("echo Test message > NUL");
#else
	std::system("");
#endif

// Set console character encoding
// Reference: https://qiita.com/BlueSilverCat/items/1e5af7fdaeaf8fd2289d
#if defined(_WIN32) || defined(_WIN64)
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1024);
#endif

	// Command line arguments
	std::vector<std::string> args(argv, argv + argc);
	cbox::options_check(args);

#ifdef CBOX_DEBUG
	std::cerr << args << std::endl;
#endif

	if (args.size() <= 1)
	{
		cbox::console::error("Option not specified. At least 1 option is required for execution.");
		return 1;
	}

	if (args[1] == "version" || cbox::command_options.contains("version"))
	{
		std::cout << "===================================================================" << std::endl;
		std::cout << "  CBOX " << cbox::cbox_version << " (Build Date: " << __DATE__ << " " << __TIME__ << ") / " << cbox::run_system << std::endl;
		std::cout << "===================================================================" << std::endl;

		if (cbox::cbox_preview)
		{
			cbox::console::warning("This version (v" + cbox::cbox_version + ") is a preview version.");
		}

		return 0;
	}
	else if (args[1] == "help" || cbox::command_options.contains("help"))
	{
		cbox::console::error("under construction");

		return 1;
	}
	else if (args[1] == "init")
	{
		return cbox::init();
	}
	else
	{
		cbox::console::error("There are no viable options");

		return 1;
	}

	return 0;
}
