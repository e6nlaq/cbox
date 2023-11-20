/****************************************************************

	shell.hpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#ifndef CBOX_SHELL_HPP
#define CBOX_SHELL_HPP

#include <string>
#include <cstdlib>
#include <cstdio>

namespace cbox
{
	std::string get_command(std::string command)
	{
		std::string result = "";

		std::FILE *fp = _popen(command.c_str(), "r");

		char buf[2048];

		while (!std::feof(fp))
		{
			std::fgets(buf, sizeof(buf), fp);
			result += buf;
		}

		std::fclose(fp);

		return result;
	}

	std::string curl(std::string url)
	{
		return get_command("curl " + url + " -s");
	}
}

#endif // CBOX_SHELL_HPP
