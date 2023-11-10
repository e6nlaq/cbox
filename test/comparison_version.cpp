/****************************************************************

	test/comparison_version.cpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdint>
#include "../version_class.hpp"
#include <algocpp/string.hpp>

// They are arranged so that FIRST < SECOND.
std::vector<std::pair<std::string, std::string>> tests = {
	{"1.0.0", "1.1.1"}, {"9.1.9", "9.2.1"}, {"0.0.0", "2"}, {"1", "2"}, {"1.3.4", "1.5"}};

std::vector<std::uint64_t> format(std::string s)
{
	std::vector<std::string> v = algocpp::string::split(s, ".");
	std::vector<std::uint64_t> result;

	std::transform(v.begin(), v.end(), std::back_inserter(result), [](std::string x)
				   { return std::stoull(x); });

	return result;
}

// =================================================================
//
// Start Test Cases
//
// =================================================================

TEST(inequality_sign, left)
{
	for (std::size_t i = 0; i < tests.size(); ++i)
	{
		EXPECT_TRUE(cbox::comparison_version(format(tests[i].second), format(tests[i].first), [](std::uint64_t a, std::uint64_t b)
											 { return a > b; }));
	}
}

TEST(inequality_sign, right)
{
	for (std::size_t i = 0; i < tests.size(); ++i)
	{
		EXPECT_TRUE(cbox::comparison_version(format(tests[i].first), format(tests[i].second), [](std::uint64_t a, std::uint64_t b)
											 { return a < b; }));
	}
}

TEST(inequality_sign, equal_left)
{
	for (std::size_t i = 0; i < tests.size(); ++i)
	{
		auto func = [](std::uint64_t a, std::uint64_t b)
		{ return a >= b; };

		EXPECT_TRUE(cbox::comparison_version(format(tests[i].second), format(tests[i].first), func));

		EXPECT_TRUE(cbox::comparison_version(format(tests[i].first), format(tests[i].first), func));

		EXPECT_TRUE(cbox::comparison_version(format(tests[i].second), format(tests[i].second), func));
	}
}

TEST(inequality_sign, equal_right)
{
	for (std::size_t i = 0; i < tests.size(); ++i)
	{
		auto func = [](std::uint64_t a, std::uint64_t b)
		{ return a <= b; };

		EXPECT_TRUE(cbox::comparison_version(format(tests[i].first), format(tests[i].second), func));

		EXPECT_TRUE(cbox::comparison_version(format(tests[i].first), format(tests[i].first), func));

		EXPECT_TRUE(cbox::comparison_version(format(tests[i].second), format(tests[i].second), func));
	}
}
