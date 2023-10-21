/****************************************************************

	args.hpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#ifndef CBOX_ARGS_HPP
#define CBOX_ARGS_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace cbox
{
	std::unordered_set<std::string> command_options;
	std::unordered_map<std::string, std::string> short_commands = {
		{"v", "version"}, {"h", "help"}};

	inline std::string is_option(std::string s)
	{
		if (s.size() < 1 || s[0] != '-')
		{
			return "";
		}

		if (s[0] == '-' && s[1] == '-' && s.size() == 2)
		{
			return "";
		}

		if (s[1] == '-')
		{
			return s.substr(2);
		}
		else
		{
			return s.substr(1);
		}
	}

	void options_check(std::vector<std::string> args)
	{
#ifdef CBOX_DEBUG
		command_options.clear();
#endif

		for (std::size_t i = 0; i < args.size(); ++i)
		{
			std::string arg = is_option(args[i]);
			if (arg != "")
			{
				if (short_commands.contains(arg))
				{
					command_options.emplace(short_commands[arg]);
				}
				else
				{
					command_options.emplace(arg);
				}
			}
		}
	}

}

#endif // CBOX_ARGS_HPP
