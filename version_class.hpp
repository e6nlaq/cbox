/****************************************************************

	version_class.hpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#ifndef CBOX_VERSION_CLASS_HPP
#define CBOX_VERSION_CLASS_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <algocpp/string.hpp>

namespace cbox
{
	namespace
	{
		template <typename T>
		std::vector<T> fill_zero(std::vector<T> v, std::size_t n) noexcept
		{
			std::vector<T> result(n, 0);
			for (std::size_t i = 0; i < v.size(); ++i)
			{
				result[i] = v[i];
			}

			return result;
		}

		template <typename fn, typename T>
		bool comparison_version(std::vector<T> a, std::vector<T> b, fn func)
		{
			std::size_t n = std::max(a.size(), b.size());

			a = fill_zero(a, n);
			b = fill_zero(b, n);

			for (std::size_t i = 0; i < n; ++i)
			{
				if (a[i] == b[i] && (std::int64_t)i != (std::int64_t)n - 1)
				{
					continue;
				}

				if (!func(a[i], b[i]))
					return false;
			}

			return true;
		}
	}

	class Version
	{
#ifdef CBOX_DEBUG
	public:
#endif
		std::vector<std::uint64_t> version;

#ifndef CBOX_DEBUG
	public:
#endif
		explicit Version(std::string s);
		explicit Version(std::vector<std::uint64_t> v);

		inline bool operator==(Version v);
		inline bool operator!=(Version v);

		inline bool operator>(Version v);
		inline bool operator<(Version v);
		inline bool operator<=(Version v);
		inline bool operator>=(Version v);
	};

	Version::Version(std::vector<std::uint64_t> v)
	{
		this->version = v;
	}

	Version::Version(std::string s)
	{
		std::vector<std::uint64_t> convert_vector;
		std::vector<std::string> split_vector = algocpp::string::split(s, ".");

		// convert all values of `split_vector` to `std::uint64_t` and assign them to `convert_vector
		std::transform(split_vector.begin(), split_vector.end(), std::back_inserter(convert_vector), [](std::string s)
					   { return std::stoull(s); });

		this->version = convert_vector;
	}

	// Operator

	inline bool Version::operator==(Version v)
	{
		return this->version == v.version;
	}

	inline bool Version::operator!=(Version v)
	{
		return this->version != v.version;
	}

	inline bool Version::operator<(Version v)
	{
		return comparison_version(this->version, v.version, [](std::int64_t a, std::int64_t b)
								  { return a < b; });
	}

	inline bool Version::operator<=(Version v)
	{
		return comparison_version(this->version, v.version, [](std::int64_t a, std::int64_t b)
								  { return a <= b; });
	}

	inline bool Version::operator>(Version v)
	{
		return comparison_version(this->version, v.version, [](std::int64_t a, std::int64_t b)
								  { return a > b; });
	}

	inline bool Version::operator>=(Version v)
	{
		return comparison_version(this->version, v.version, [](std::int64_t a, std::int64_t b)
								  { return a >= b; });
	}
}

#endif // CBOX_VERSION_CLASS_HPP
