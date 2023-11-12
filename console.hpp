/****************************************************************

	console.hpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#ifndef CBOX_CONSOLE_HPP
#define CBOX_CONSOLE_HPP

#include <iostream>
#include <string>

namespace cbox
{
	namespace console
	{
		inline void line_delete(bool newline = false) noexcept
		{
			std::cout << "\x1b[2K\x1b[G";

			if (newline)
				std::cout << std::endl;
			else
				std::cout << std::flush;
		}

		inline void __log_print(std::string title, std::string message, std::ostream &out, bool newline = false) noexcept
		{
			line_delete();
			out << "[ \x1b[1m" << title << "\x1b[m ] " << message;

			if (newline)
				out << std::endl;
			else
				out << std::flush;
		}

		inline void run(std::string message) noexcept
		{
			__log_print("\x1b[5mRUN", message, std::cout);
		}

		inline void error(std::string message) noexcept
		{
			__log_print("\x1b[31mERROR", message, std::cerr, true);
		}

		inline void warning(std::string message) noexcept
		{
			__log_print("\x1b[33mWARN", message, std::cerr, true);
		}

		inline void ok(std::string message) noexcept
		{
			__log_print("\x1b[32mOK", message, std::cout, true);
		}

		inline void log(std::string message) noexcept
		{
			__log_print("\x1b[34mLOG", message, std::cout, true);
		}
	}
}

#endif // CBOX_CONSOLE_HPP
