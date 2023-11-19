/****************************************************************

	input.hpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#ifndef CBOX_INPUT_HPP
#define CBOX_INPUT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "args.hpp"

namespace cbox
{
	std::string user_input(std::string question, std::string default_value)
	{
		if (cbox::command_options.contains("yes"))
		{
			return default_value;
		}

		std::cout << question << "(" << default_value << "): ";
		std::string inp;
		std::getline(std::cin, inp);

		if (inp == "")
		{
			return default_value;
		}
		else
		{
			return inp;
		}
	}

	bool yesno(std::string inp)
	{
		for (std::size_t i = 0; i < inp.size(); ++i)
		{
			if (!std::isalpha(inp[i]))
			{
				return false;
			}
		}

		std::transform(inp.begin(), inp.end(), inp.begin(), ::tolower);

		if (inp == "yes" || inp == "y")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

#endif // CBOX_INPUT_HPP
