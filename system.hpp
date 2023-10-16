
#ifndef CBOX_SYSTEM_HPP
#define CBOX_SYSTEM_HPP

#include <string>

namespace cbox
{

#if defined(__linux__)

#ifdef __x86_64
	std::string run_system = "Linux 64bit";
#else
	std::string run_system = "Linux 32bit";
#endif // __x86_64

#elif defined(__MACH__)

	std::string run_system = "macOS";

#elif defined(__CYGWIN__)

	std::string run_system = "Cygwin";

#elif defined(_WIN64)

	std::string run_system = "Windows 64bit";

#elif defined(_WIN32)

	std::string run_system = "Windows 32bit";

#elif defined(__unix__)

	std::string run_system = "UNIX";

#elif defined(__MINGW64__)

	std::string run_system = "MSYS2 64bit";

#elif defined(__MINGW32__)

	std::string run_system = "MSYS2 32bit";

#else

	std::string run_system = "Unknown OS";

#endif

#if defined(_WIN32) || defined(_WIN64)

	std::string null_file = "NUL";

#else

	std::string null_file = "/dev/null";

#endif

}

#endif // CBOX_SYSTEM_HPP
