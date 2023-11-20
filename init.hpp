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
#include <iostream>
#include <fstream>
#include "console.hpp"
#include "input.hpp"
#include "file.hpp"

namespace cbox
{
	int init()
	{
		nlohmann::json cbox_info;

		if (std::filesystem::is_regular_file("cbox_info.json"))
		{
			cbox::console::error("Already configured.");
			return 1;
		}

		cbox_info["name"] = cbox::user_input("Project name", cbox::get_folder_name(std::filesystem::current_path()));
		cbox_info["description"] = cbox::user_input("Description", "");
		cbox_info["version"] = cbox::user_input("Version", "1.0.0");
		cbox_info["dependence"] = nlohmann::json::object();
		cbox_info["author"] = cbox::user_input("Author", "unknown");
		cbox_info["author_email"] = cbox::user_input("Email", "example@example.com");
		cbox_info["license"] = cbox::user_input("License", "MIT");

		std::ofstream info_file("cbox_info.json");
		info_file << std::setw(4) << cbox_info << std::endl;

		cbox::console::ok("Output settings to `cbox_info.json`.");

		return 0;
	}
}

#endif // CBOX_INIT_HPP
