/****************************************************************

	test/options_check.cpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#define CBOX_DEBUG

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../args.hpp"

TEST(single, flag)
{
	for (auto x : cbox::short_commands)
	{
		cbox::options_check(std::vector<std::string>{x.first});
		EXPECT_EQ(cbox::command_options, std::unordered_set<std::string>{x.second});
	}
}

TEST(two, flag)
{
	for (auto x : cbox::short_commands)
	{
		cbox::options_check(std::vector<std::string>{x.second});
		EXPECT_EQ(cbox::command_options, std::unordered_set<std::string>{x.second});
	}
}

TEST(none, flag)
{
	std::vector<std::string> test;
	for (int i = 0; i < 10000; ++i)
	{
		test.emplace_back(std::to_string(i));
		cbox::options_check(test);
		EXPECT_EQ(cbox::command_options, std::unordered_set<std::string>{});
	}
}
