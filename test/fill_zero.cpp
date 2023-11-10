/****************************************************************

	test/fill_zero.cpp

	Copyright (c) 2023 e6nlaq
	This file is part of cbox.
	See https://github.com/e6nlaq/cbox for more information.

****************************************************************/

#include <gtest/gtest.h>
#include <vector>
#include <cstdint>
#include "../version_class.hpp"

TEST(fill_zero, size)
{
	for (std::size_t i = 0; i < 10000; ++i)
	{
		EXPECT_EQ(cbox::fill_zero(std::vector<std::uint64_t>(0), i).size(), i);
	}
}

TEST(fill_zero, equal)
{
	std::vector<std::uint64_t> v = {};
	for (std::size_t i = 0; i < 10000; ++i)
	{
		v.emplace_back(i);
		EXPECT_EQ(cbox::fill_zero(v, v.size()), v);
	}
}
