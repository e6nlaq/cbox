/****************************************************************

	test/is_option.cpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#include <gtest/gtest.h>
#include <string>
#include "../args.hpp"

TEST(single, lower)
{
	for (int i = 0; i <= ('z' - 'a'); ++i)
	{
		std::string test_char = {(char)('a' + i)};
		EXPECT_EQ(cbox::is_option("-" + test_char), test_char);
	}
}

TEST(single, upper)
{
	for (int i = 0; i <= ('Z' - 'A'); ++i)
	{
		std::string test_char = {(char)('A' + i)};
		EXPECT_EQ(cbox::is_option("-" + test_char), test_char);
	}
}

TEST(two, lower)
{
	for (int i = 0; i <= ('z' - 'a'); ++i)
	{
		std::string test_char = {(char)('a' + i)};
		EXPECT_EQ(cbox::is_option("--" + test_char), test_char);
	}
}

TEST(two, upper)
{
	for (int i = 0; i <= ('Z' - 'A'); ++i)
	{
		std::string test_char = {(char)('A' + i)};
		EXPECT_EQ(cbox::is_option("--" + test_char), test_char);
	}
}

TEST(invaid, only_minus)
{
	std::string test = "";
	for (int i = 0; i < 2; ++i)
	{
		EXPECT_EQ(cbox::is_option(test), "");
		test += "-";
	}
}