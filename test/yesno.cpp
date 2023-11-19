/****************************************************************

	test/yesno.cpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../input.hpp"

const std::vector<std::string> yes_list = {"yes", "y", "YES", "Y", "YeS", "yES", "Yes", "YEs", "yeS"};

TEST(yes, vec)
{
	for (std::size_t i = 0; i < yes_list.size(); ++i)
	{
		EXPECT_TRUE(cbox::yesno(yes_list[i]));
	}
}

TEST(no, ascii)
{
	for (int i = 0; i < 64; ++i)
	{
		if ('A' + i != 'y' && 'A' + i != 'Y')
		{
			EXPECT_FALSE(cbox::yesno(std::string{(char)('A' + i)}));
		}
	}
}
