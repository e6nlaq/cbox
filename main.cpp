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

// #define CBOX_DEBUG

#ifdef CBOX_DEBUG
#include <algocpp/io.hpp>
#endif

int main(int argc, char const *argv[])
{
	std::vector<std::string> args(argv, argv + argc);

	cbox::options_check(args);

#ifdef CBOX_DEBUG
	std::cerr << args << std::endl;
#endif

	if (args[1] == "version" || cbox::command_options.contains("version"))
	{
		std::cout << "======================================" << std::endl;
		std::cout << "  CBOX " << cbox::cbox_version << " / " << cbox::run_system << std::endl;
		std::cout << "======================================" << std::endl;

		if (cbox::cbox_preview)
		{
		}
	}

	return 0;
}
