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
	const std::unordered_map<std::string, std::string> short_commands = {

	};
}

#endif // CBOX_ARGS_HPP
