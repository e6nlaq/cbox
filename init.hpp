/****************************************************************

	init.hpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#ifndef CBOX_INIT_HPP
#define CBOX_INIT_HPP

#include <nlohmann/json.hpp>
#include <filesystem>
#include "console.hpp"

namespace cbox
{
	int init()
	{
		nlohmann::json default_json = {

		};

		if (std::filesystem::is_regular_file("cbox_info.json"))
		{
			cbox::console::error("Already configured.");
			return 1;
		}

		return 0;
	}
}

#endif // CBOX_INIT_HPP
