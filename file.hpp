/****************************************************************

	file.hpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#ifndef CBOX_FILE_HPP
#define CBOX_FILE_HPP

#include <filesystem>
#include <string>
#include <algocpp/string.hpp>

namespace cbox
{
	std::string get_folder_name(const std::string s)
	{
#if defined(_WIN32) || defined(_WIN64)
		return algocpp::string::split(s, "\\").back();
#else
		return algocpp::string::split(s, "/").back();
#endif
	}

	std::string get_folder_name(const std::filesystem::path p)
	{
		return get_folder_name(p.string());
	}
}

#endif // CBOX_FILE_HPP
